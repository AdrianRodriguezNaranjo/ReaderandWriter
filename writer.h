#ifndef WRITER_H
#define WRITER_H

#include <QSemaphore>
#include <QThread>

class Writer : public QThread
{
public:
    explicit Writer(QObject *parent = nullptr);
    explicit Writer(QSemaphore *writing,
                    int numWriter,
                    QSemaphore *consoleAvailable);

protected:
    void run() override;

private:
    QSemaphore *writing;
    int numWriter;
    QSemaphore *consoleAvailable;
};

#endif // WRITER_H
