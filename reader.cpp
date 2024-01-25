#include "reader.h"
#include <iostream>

Reader::Reader(QObject *parent)
    : QThread{parent}
{}

Reader::Reader(const int numReader,
               const int readcount,
               QSemaphore *exclu,
               QSemaphore *writing,
               QSemaphore *consoleAvailable)
{
    this->numReader = numReader;
    this->readcount = readcount;
    this->exclu = exclu;
    this->writing = writing;
    this->consoleAvailable = consoleAvailable;
}

void Reader::run(){
    for(int i = 1; i <= numReader; ++i){
        exclu->acquire();
        readcount++;
        if(readcount >= 1){
            writing->acquire();
        }
        exclu->release();

        consoleAvailable->acquire();
        std::cout << "Reader " << i << " is consulting the database" << '\n';
        consoleAvailable->release();

        exclu->acquire();
        readcount--;
        if(readcount == 0){
            writing->release();
        }
        exclu->release();
    }
}
