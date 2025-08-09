#include "stopwatch.h"


Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{

}
    void Stopwatch::on_start_stop() {
        if (!isTimer) {
               startTime = QTime::currentTime();
               timer->start(100);
               butStartStopText = "Стоп";
               isTimer = true;


              } else {
               timer->stop();
               butStartStopText = "Старт";
               isTimer = false;
              }
    }

    void Stopwatch::setTextTimer() {
        QTime currentTime = QTime::currentTime();
        int elapsedSeconds = startTime.secsTo(currentTime);
        timerText = QTime(0, 0, 0).addSecs(elapsedSeconds).toString("hh:mm:ss");
    }

    void Stopwatch::setBrowserText() {
        if (isTimer) {
                  QTime currentTime = QTime::currentTime();
                  int elapsedMs;
                  if (lapCount == 1) {
                      elapsedMs = startTime.msecsTo(currentTime);
                  } else {
                      elapsedMs = lastLapTime.msecsTo(currentTime);
                  }
                   lapBrowserText = QString("Круг %1, время: %2 сек").arg(lapCount).arg(elapsedMs / 1000.0, 0, 'f', 2);
                   lastLapTime = currentTime;
                   lapCount++;
               }
    }

    void Stopwatch::clear() {
        isTimer = false;
        butStartStopText = "Старт";
        lapCount = 1;
        startTime = QTime();
        lastLapTime = QTime();
            if ( timer->isActive()) {
                timer->stop();
            }
    }







