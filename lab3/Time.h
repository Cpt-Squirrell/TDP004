#pragma once
#include <string>

class Clock 
{
    public:
        Clock() : hour(0), minutes(0), seconds(0) {};
        Clock(std::string time);
        Clock(int hour, int minutes, int seconds);

        std::string toString(bool asLatin = false);
        Clock& fromString(const std::string& string);

        inline Clock& operator+(const Clock& rhs);
        inline Clock& operator-(const Clock& rhs);
        Clock& operator+(int seconds);
        Clock& operator-(int seconds);
        inline Clock& operator++();
        inline Clock& operator--();
        inline Clock  operator++(int);
        inline Clock  operator--(int);
        inline bool operator< (const Clock& rhs);
        inline bool operator<=(const Clock& rhs);
        inline bool operator> (const Clock& rhs);
        inline bool operator>=(const Clock& rhs);
        inline bool operator==(const Clock& rhs);
        inline bool operator!=(const Clock& rhs);

        inline int getHour() { return hour; }
        inline int getMinutes() { return minutes; }
        inline int getSeconds() { return seconds; }

        void setTime(int hour, int minutes, int seconds) {
            this->hour = hour;
            this->minutes = minutes;
            this->seconds = seconds;
        }

    private:
        void validateTime(); // Handles overflowing numbers (e.g. >= 60 seconds)
        int toSeconds() const; // Converts the clock into seconds from 00:00:00
        int hour, minutes, seconds;
        static const int DAY{86400}, HOUR{3600}, MINUTE{60};
};

std::ostream& operator<<(const std::ostream&, const Clock& rhs);
std::istream& operator>>(std::istream& lhs, Clock& rhs);