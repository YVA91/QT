#include "stopwatch.h"



Stopwatch::Stopwatch(QObject *parent) : QObject(parent)

{
    timer = new QTimer(this);

}

void Stopwatch::on_start()
{
    startTime = QTime(0, 0, 0);
    connect(timer, &QTimer::timeout, this, &Stopwatch::setTextTimer);
    timer->start(100);
    lastLapTime = startTime;
}

void Stopwatch::on_stop()
{
    timer->stop();
}

void Stopwatch::setTextTimer() {
    startTime = startTime.addMSecs(100);
    emit SetStopWath(startTime.toString("hh:mm:ss.z"));
 }



int Stopwatch::setBrowserText() {

   int set_times;
   set_times = lastLapTime.msecsTo(startTime);
   qDebug() << startTime;
   lastLapTime = startTime;
   return set_times;

}

void Stopwatch::clear() {

    startTime = QTime();
    lastLapTime = QTime();
        if (timer->isActive()) {
            timer->stop();
        }
    }







