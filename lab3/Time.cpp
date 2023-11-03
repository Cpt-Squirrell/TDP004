#include "Time.h"


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

/*Clock& Clock::fromString(const std::string& string)
{
    setTime(string);
    return *this;
}*/

Clock& Clock::operator+(const Clock& rhs)
{

}

Clock& Clock::operator-(const Clock& rhs)
{

}

void Clock::operator++()
{

}

void Clock::operator--()
{

}

void Clock::operator++(int)
{

}

void Clock::operator--(int)
{

}

Clock& Clock::operator<(const Clock& rhs)
{

}

Clock& Clock::operator>(const Clock& rhs)
{

}

Clock& Clock::operator==(const Clock& rhs)
{

}

Clock& Clock::operator!=(const Clock& rhs)
{

}

int Clock::getHour() {
    return hour;
}

int Clock::getMinutes() {
    return minutes;
}

int Clock::getSeconds() {
    return seconds;
}

void Clock::setTime(int hour, int minutes, int seconds) {
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
}

Clock::~Clock()
{

}