#include "reader.h"
#include "writer.h"

#include <QCoreApplication>
#include <QSemaphore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    constexpr int numReader = 20;
    constexpr int numWriter = 10;
    constexpr int readcount = 0;

    QSemaphore exclu(1);
    QSemaphore writing(1);
    QSemaphore consoleAvailable(1);

    Reader reader (numReader,
                  readcount,
                  &exclu,
                  &writing,
                  &consoleAvailable);

    Writer writer(&writing,numWriter,&consoleAvailable);

    reader.start();
    writer.start();
    reader.wait();
    writer.wait();

    return 0;
}
