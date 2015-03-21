#include <calendar.h>
#include <iostream>

TCalendar::TCalendar()
{
    currentDate = QDate::currentDate();
    currentTime = QTime::currentTime();
    std::cerr<< currentDate.dayOfWeek() << currentTime.hour() << std::endl;
}

void TCalendar::updateDateAndTime()
{
    currentDate = QDate::currentDate();
    currentTime = QTime::currentTime();
}

