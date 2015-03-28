#ifndef LESSONTIMER_H
#define LESSONTIMER_H

#include <QObject>
#include <QTime>

class LessonTimer : public QObject
{
    Q_OBJECT
public:
    explicit LessonTimer(int interval, QObject *parent = 0);
    ~LessonTimer();

signals:

public slots:
    void start();
    int clearTime();
private:
   int interval;
   QTime astroTime;
   QTime intervalTime;
   int pauseTime;


};

#endif // LESSONTIMER_H
