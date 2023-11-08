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

Clock& Clock::fromString(const std::string& string)
{
    std::istringstream converter{string};
    converter >> hour; 
    if(converter.fail())
        throw std::invalid_argument("Failure converting string input for hour.");
    converter.ignore(1); converter >> minutes; 
    if(converter.fail())
        throw std::invalid_argument("Failure converting string input for minutes.");
    converter.ignore(1); converter >> seconds;
    if(converter.fail())
        throw std::invalid_argument("Failure converting string input for seconds.");
    
    if(converter.good()) // read am / pm
    {
        std::string am_pm{};
        converter >> am_pm;
        if(am_pm != "am" && am_pm != "pm")
            throw std::invalid_argument("Expected am or pm at the end of string input.");
        if(hour > 12 || hour < 1)
            throw std::invalid_argument("Expected hour in the range 1 to 12 for am/pm string input.");
        if(am_pm == "pm")
            hour = (hour+12)%24;
    }

    if(hour > 23  || hour < 0)
        throw std::invalid_argument("Attempted to assign value out of bounds to hour");
    if(minutes > 59 || minutes < 0)
        throw std::invalid_argument("Attempted to assign value out of bounds to minutes");
    if(seconds > 59 || seconds < 0)
        throw std::invalid_argument("Attempted to assign value out of bounds to seconds");
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

Clock& Clock::operator+=(const int added_seconds)
{
    Clock temp = (*this + added_seconds);
    this->seconds = temp.seconds;
    this->minutes = temp.minutes;
    this->hour    = temp.hour;
    return *this;
}

Clock& Clock::operator-=(const int removed_seconds)
{
    Clock temp = (*this - removed_seconds);
    this->seconds = temp.seconds;
    this->minutes = temp.minutes;
    this->hour    = temp.hour;
    return *this;
}

Clock& Clock::operator+=(const Clock& rhs)
{
    return (this->operator+=(rhs.toSeconds()));
}

Clock& Clock::operator-=(const Clock& rhs)
{
    return (this->operator-=(rhs.toSeconds()));
}

Clock  Clock::operator+ (int added_seconds)
{
    Clock temp{ (added_seconds/DAY)%24, (added_seconds/HOUR)%60, (added_seconds)%60 };
    return (this->operator+(temp));
}

Clock  Clock::operator- (int removed_seconds) {
    Clock temp{ (removed_seconds/DAY)%24, (removed_seconds/HOUR)%60, (removed_seconds)%60 };
    return (this->operator-(temp));
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

int Clock::getHour() const
{
    return hour;
}

int Clock::getMinutes() const
{
    return minutes;
}

int Clock::getSeconds() const
{
    return seconds;
}

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

std::istream& operator>>(std::istream& lhs, Clock& rhs) {
    std::string input{};
    lhs >> input;
    try{
        rhs.fromString(input);
    }
    catch(const std::exception& e){
        lhs.setstate(std::ios::failbit); // Set failbit when extraction is incompatible with clock format
    }
    
    return lhs;
}