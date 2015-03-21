#include <activationtime.h>

TTime::TTime()
{
    dayOfWeek.clear();
    currentDate = QDate::currentDate();
    currentTime = QTime::currentTime();
}

void TTime::updateDateAndTime()
{
    currentDate = QDate::currentDate();
    currentTime = QTime::currentTime();
}

bool TTime::ReadyToPlay() {
    if(dayOfWeek.find(currentDate.dayOfWeek()) != dayOfWeek.end() &&
      hoursToPlay == currentTime.hour() &&
      minuteToPlay == currentTime.minute())
    {
        return true;
    }
    return false;
}
