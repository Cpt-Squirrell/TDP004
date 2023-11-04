#include "Time.h"
#include <cmath>

Clock::Clock(std::string time)
{
    //parse string to align with our tests and set the internal data
}

Clock::Clock(int hour, int minutes, int seconds)
{
    setTime(hour, minutes, seconds);
}

std::string Clock::toString(bool asLatin = false)
{
    
}

Clock& Clock::fromString(const std::string& string)
{

}

inline Clock& Clock::operator+(const Clock& rhs)
{
    return *this + (rhs.hour * 3600 + rhs.minutes * 60 + rhs.seconds);
}

inline Clock& Clock::operator-(const Clock& rhs)
{
    return *this - (rhs.hour * 3600 + rhs.minutes * 60 + rhs.seconds);
}

Clock& Clock::operator+(int seconds)
{
    seconds -= DAY * std::floor(seconds / DAY); // Remove extra days
    int addedHours{std::floor(seconds / HOUR)},
        addedMinutes{std::floor(seconds / MINUTE)};
    hour += addedHours;
    minutes += addedMinutes;
    seconds += seconds - addedMinutes * 60 - addedHours * 3600;
}

Clock& Clock::operator-(int seconds)
{
    seconds -= DAY * std::floor(seconds / DAY); // Remove extra days
    int removedHours{std::floor(seconds / HOUR)},
        removedMinutes{std::floor(seconds / MINUTE)};
    hour -= removedHours;
    minutes -= removedMinutes;
    seconds += seconds - removedMinutes * 60 - removedMinutes * 3600;
}

Clock& Clock::operator++()
{
    this->seconds++;
    this->validateTime();
    return *this;
}

Clock& Clock::operator--()
{
    this->seconds--;
    this->validateTime();
    return *this;
}

Clock Clock::operator++(int)
{
    Clock oldTime = *this;
    this->seconds++;
    this->validateTime();
    return oldTime;
}

Clock Clock::operator--(int)
{
    Clock oldTime = *this;
    this->seconds--;
    this->validateTime();
    return oldTime;
}

bool Clock::operator<(const Clock& rhs)
{
    if (this->toSeconds() < rhs.toSeconds())
        return true;
    else
        return false;
}

bool Clock::operator<=(const Clock& rhs)
{
    if (this->toSeconds() <= rhs.toSeconds())
        return true;
    else
        return false;
}

bool Clock::operator>(const Clock& rhs)
{
    return !(*this <= rhs);
}

bool Clock::operator>=(const Clock& rhs)
{
    return !(*this < rhs);
}

bool Clock::operator==(const Clock& rhs)
{

}

bool Clock::operator!=(const Clock& rhs)
{

}

void Clock::setTime(int hour, int minutes, int seconds) {
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Clock::validateTime()
{
    if (seconds > 59) {
        seconds = 0;
        minutes++;
    }
    
    if (seconds < 0) {
        minutes--;
        seconds = 59;
    }
    
    if (minutes > 59) {
        minutes = 0;
        hour++;
    }

    if (minutes < 0) {
        hour--;
        minutes = 59;
    }

    if (hour > 23)
        hour = 0;

    if (hour < 0)
        hour = 23;
}

int Clock::toSeconds() const {
    return this->hour * 3600 + this->minutes * 60 + this->seconds;
}