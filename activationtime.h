#ifndef ACTIVATIONTIME
#define ACTIVATIONTIME

#include <QTime>
#include <QDate>
#include <QSet>

class TTime
{
public:
    TTime();
    void updateDateAndTime();
    bool ReadyToPlay();

public:
    QDate currentDate;
    QTime currentTime;
    QSet <int> dayOfWeek;
    int hoursToPlay;
    int minuteToPlay;
};

#endif // ACTIVATIONTIME

