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
    int setTextTimer();
    int setBrowserText(int lap_count);
    void clear();

    bool isTimer = false;
    QTime startTime;
    QTimer *timer;
    QTime lastLapTime;
    //int lapCount = 1;
    //QString lapBrowserText = "";

};

#endif // STOPWATCH_H
