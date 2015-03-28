#include "lessontimer.h"

LessonTimer::LessonTimer(int interval, QObject *parent) : QObject(parent)
{
if (interval>0)
    this->interval=interval;
else
    this->interval=1000;

pauseTime=0;
}

LessonTimer::~LessonTimer()
{

}

void LessonTimer::start()
{
    astroTime.start();
    intervalTime.start();
    pauseTime=0;

}
int LessonTimer::clearTime()
{
   const int epsilon=interval/10;
   int waitingTime=intervalTime.elapsed();
    if (waitingTime>interval+epsilon)
        pauseTime += waitingTime;


    intervalTime.restart();
   return (astroTime.elapsed()-pauseTime)/interval;


}
