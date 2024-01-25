#include "writer.h"
#include <iostream>

Writer::Writer(QObject *parent)
    : QThread{parent}
{}

Writer::Writer(QSemaphore *writing,
               int numWriter,
               QSemaphore *consoleAvailable)
{
    this->writing = writing;
    this->numWriter = numWriter;
    this->consoleAvailable = consoleAvailable;
}

void Writer::run(){
    for(int i = 1; i <= numWriter; ++i){
        writing->acquire();
        consoleAvailable->acquire();
        std::cout << "Writer " << i << " is changing the database" << '\n';
        consoleAvailable->release();
        writing->release();
    }
}
