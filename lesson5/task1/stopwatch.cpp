#include "stopwatch.h"


Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(100);

}
    void Stopwatch::on_start_stop() {
        if (!isTimer) {
               startTime = QTime::currentTime();
               timer->start();
               isTimer = true;
              } else {
               timer->stop();
               isTimer = false;
              }
    }

    int Stopwatch::setTextTimer() {
        QTime currentTime = QTime::currentTime();
        int time = startTime.msecsTo(currentTime);
        return time;
    }

    int Stopwatch::setBrowserText(int lap_count) {
        int set_times;
        if (isTimer) {
                  QTime currentTime = QTime::currentTime();
                  if (lap_count == 1) {
                      set_times = startTime.msecsTo(currentTime);
                  } else {
                      set_times = lastLapTime.msecsTo(currentTime);

                  }
                   lastLapTime = currentTime;
                   return set_times;
               }
    }

    void Stopwatch::clear() {
        isTimer = false;
        startTime = QTime();
        lastLapTime = QTime();
            if ( timer->isActive()) {
                timer->stop();
            }
    }







