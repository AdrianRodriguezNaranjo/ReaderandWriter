#ifndef READER_H
#define READER_H

#include <QSemaphore>
#include <QThread>

class Reader : public QThread
{
public:
    explicit Reader(QObject *parent = nullptr);
    explicit Reader(const int numReader,
                    const int readcount,
                    QSemaphore *exclu,
                    QSemaphore *writing,
                    QSemaphore *consoleAvailable);

protected:
    void run() override;

private:
    int numReader;
    int readcount;
    QSemaphore *exclu;
    QSemaphore *writing;
    QSemaphore *consoleAvailable;
};

#endif // READER_H
