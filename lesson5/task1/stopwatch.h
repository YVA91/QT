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

signals:
    void SetStopWath(const QString& time);

 public slots:
    void on_start();
    void on_stop();
    void  setTextTimer();
    int setBrowserText();
    void clear();

 private:
    QTime startTime;
    QTimer *timer;
    QTime lastLapTime;
};

#endif // STOPWATCH_H
