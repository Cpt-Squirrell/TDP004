#include <cmath>
#include <sstream>
#include <iomanip>
#include "Time.h"

Clock::Clock(int hour, int minutes, int seconds)
{
    setTime(hour, minutes, seconds);
}

std::string Clock::toString(bool asLatin) const
{
    if (asLatin)
        return (std::stringstream{} << std::setw(2) << std::setfill('0')
                    << (hour <= 12 ? hour : hour - 12) << ':' 
                    << minutes << ':' << seconds
                    << (hour < 12 ? " AM" : " PM")).str();
    else
        return (std::stringstream{} << std::setw(2) << std::setfill('0')
                    << hour << ':' << minutes << ':' << seconds).str();
}

Clock::Clock(const std::string& time)
{
    fromString(time);
}

Clock& Clock::fromString(const std::string& string)
{
    std::istringstream converter{string};
    converter >> hour; converter.ignore(1); converter >> minutes; converter.ignore(1); converter >> seconds;
    return *this;
}

Clock& Clock::operator+(int seconds)
{
    for(int to_add = 0; to_add < seconds; ++to_add)
    {
        this->seconds++;
        this->validateTime();
    }
    return *this;
}

Clock& Clock::operator-(int seconds)
{
    for(int to_sub = 0; to_sub < seconds; ++to_sub)
    {
        this->seconds--;
        this->validateTime();
    }
    return *this;
}

Clock& Clock::operator+(const Clock& rhs)
{
    return *this + (rhs.hour * HOUR + rhs.minutes * MINUTE + rhs.seconds);
}

Clock& Clock::operator-(const Clock& rhs)
{
    return *this - (rhs.hour * HOUR + rhs.minutes * MINUTE + rhs.seconds);
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

bool Clock::operator==(const Clock& rhs) const
{
    return this->toSeconds() == rhs.toSeconds();
}

bool Clock::operator!=(const Clock& rhs) const
{
    return !(*this == rhs);
}

int Clock::getHour()    { return hour;    }
int Clock::getMinutes() { return minutes; }
int Clock::getSeconds() { return seconds; }

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
    return this->hour * HOUR + this->minutes * MINUTE + this->seconds;
}

std::ostream& operator<<(std::ostream& lhs, const Clock& rhs)
{
    return lhs << rhs.toString(false);
}

std::istream& operator>>(std::istream& lhs, Clock& rhs)
{
    std::string input{};
    lhs >> input;
    rhs.fromString(input);
    return lhs;
}