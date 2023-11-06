#include <string>
#pragma once

class Clock 
{
    public:
        Clock() : hour(0), minutes(0), seconds(0) {};
        Clock(int hour, int minutes, int seconds);
        Clock(const std::string& time);

        std::string toString(bool asLatin = false) const;
        Clock& fromString(const std::string& string);

        Clock& operator+=(int seconds);
        Clock& operator-=(int seconds);
        Clock  operator+ (int seconds);
        Clock  operator- (int seconds);

        Clock& operator+=(const Clock& rhs);
        Clock& operator-=(const Clock& rhs);
        Clock  operator+ (const Clock& rhs);
        Clock  operator- (const Clock& rhs);
        
        Clock& operator++();
        Clock& operator--();
        Clock  operator++(int);
        Clock  operator--(int);
        bool operator< (const Clock& rhs) const;
        bool operator<=(const Clock& rhs) const;
        bool operator> (const Clock& rhs) const;
        bool operator>=(const Clock& rhs) const;
        bool operator!=(const Clock& rhs) const;
        bool operator==(const Clock& rhs) const;

        int getHour();
        int getMinutes();
        int getSeconds();

        void setTime(int hour, int minutes, int seconds);

    private:
        void validateTime(); // Handles overflowing numbers (e.g. >= 60 seconds)
        int toSeconds() const; // Converts the clock into seconds from 00:00:00
        int hour, minutes, seconds;

        // Seconds conversions for days, hours, and minutes
        static const int DAY{86400}, HOUR{3600}, MINUTE{60};
};

std::ostream& operator<<(std::ostream& lhs, const Clock& rhs);
std::istream& operator>>(std::istream& lhs, Clock& rhs);