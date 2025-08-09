#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QDebug>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);

    void on_start_stop();
    void setTextTimer();
    void setBrowserText();
    void clear();

    bool isTimer = false;
    QTime startTime;
    QTimer *timer;
    QTime lastLapTime;
    int lapCount = 1;
    QString butStartStopText = "";
    QString timerText = "";
    QString lapBrowserText = "";

};

#endif // STOPWATCH_H
