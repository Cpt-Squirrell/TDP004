#include <cmath>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Time.h"

Clock::Clock(int hour, int minutes, int seconds)
{
    setTime(hour, minutes, seconds);
}

std::string Clock::toString(bool asLatin) const
{
    if (asLatin) {
        int latinHour = hour <= 12 ? hour : hour - 12;
        if (latinHour == 0) latinHour = 12;
        return (std::stringstream{} 
                    << std::setw(2) << std::setfill('0') << latinHour << ':' 
                    << std::setw(2) << std::setfill('0') << minutes << ':'
                    << std::setw(2) << std::setfill('0') << seconds
                    << (hour < 12 ? " am" : " pm")).str();
    } else
        return (std::stringstream{}
                    << std::setw(2) << std::setfill('0') << hour << ':' 
                    << std::setw(2) << std::setfill('0') << minutes << ':'
                    << std::setw(2) << std::setfill('0') << seconds).str();
}

Clock::Clock(const std::string& time)
{
    fromString(time);
}

//TODO: Add exceptions to incompatible values
Clock& Clock::fromString(const std::string& string)
{
    std::istringstream converter{string};
    converter >> hour; converter.ignore(1); converter >> minutes; converter.ignore(1); converter >> seconds;
    return *this;
}

Clock Clock::operator+(const Clock& rhs)
{
    int seconds = this->seconds + rhs.seconds,
        minutes = this->minutes + rhs.minutes,
        hour    = this->hour    + rhs.hour;

    if (seconds > 59) {
        seconds -= 60;
        minutes++;
    }

    if (minutes > 59) {
        minutes -= 60;
        hour++;
    }

    if (hour > 23)
        hour -= 24;

    return Clock{hour, minutes, seconds};
}

Clock Clock::operator-(const Clock& rhs)
{
    int seconds = this->seconds - rhs.seconds,
        minutes = this->minutes - rhs.minutes,
        hour   = this->hour    - rhs.hour;

    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }

    if (minutes < 0) {
        minutes += 60;
        hour--;
    }

    if (hour > 23)
        hour -= 24;

    return Clock{hour, minutes, seconds};
}

Clock& Clock::operator+=(const int seconds) {
    return *this = *this + seconds;
}

Clock& Clock::operator-=(const int seconds) {
    return *this = *this - seconds;
}

Clock& Clock::operator+=(const Clock& rhs) {
    return *this = *this + rhs.toSeconds();
}
Clock& Clock::operator-=(const Clock& rhs) {
    return *this = *this - rhs.toSeconds();
}

//TODO: Fix operator
Clock  Clock::operator+ (int seconds) {
    seconds -= DAY * (seconds / DAY); // Remove extra days
    int addedHour{seconds / HOUR};
    seconds -= addedHour * HOUR;
    int addedMinutes{seconds / MINUTE};
    seconds -= addedMinutes * MINUTE;
    Clock returnClock{
        this->hour + addedHour,
        this->minutes + addedMinutes,
        (this->seconds + seconds) % 60
    };
    returnClock.validateTime();
    return returnClock;
}

// TODO: Implement fixes for operator+ into operator-
Clock  Clock::operator- (int rhs) {
    int hour = 0, minutes = 0, seconds = 0;
    rhs -= DAY * (int)std::floor(rhs / DAY); // Remove extra days
    int removedHours{(int)std::floor(rhs / HOUR)},
        removedMinutes{(int)std::floor(rhs / MINUTE)};
    hour -= removedHours;
    minutes -= removedMinutes;
    seconds += rhs - removedMinutes * 60 - removedMinutes * 3600;
    return Clock{hour, minutes, seconds};
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

bool Clock::operator<(const Clock& rhs) const
{
    if (this->toSeconds() < rhs.toSeconds())
        return true;
    else
        return false;
}

bool Clock::operator<=(const Clock& rhs) const
{
    if (this->toSeconds() <= rhs.toSeconds())
        return true;
    else
        return false;
}

bool Clock::operator>(const Clock& rhs) const
{
    return !(*this <= rhs);
}

bool Clock::operator>=(const Clock& rhs) const
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
    if (hour < 0 || minutes < 0 || seconds < 0)
        throw std::invalid_argument("Attempted to assign negative value to a clock.");
    if (hour > 23 || minutes > 59 || seconds > 59)
        throw std::invalid_argument("Attempted to assign too large value to clock.");

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

std::ostream& operator<<(std::ostream& lhs, const Clock& rhs) {
    return lhs << rhs.toString(false);
}

// Set failbit when extraction is incompatible with clock format
std::istream& operator>>(std::istream& lhs, Clock& rhs) {
    std::string input{};
    lhs >> input;
    rhs.fromString(input);
    return lhs;
}