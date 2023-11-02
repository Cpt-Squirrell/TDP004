#include <iostream>
#include <string>

class Clock 
{
    public:
        Clock() : hour(0), minutes(0), seconds(0) {};
        Clock(std::string time);
        Clock(int hour, int minutes, int seconds);

        std::string toString(bool asLatin = false);
        Clock& fromString(const std::string& string);

        Clock& operator+(const Clock& rhs);
        Clock& operator-(const Clock& rhs);
        void operator++();
        void operator--();
        friend std::ostream& operator<<(const std::ostream&, const Clock& rhs);
        friend std::istream& operator>>(std::istream& lhs, Clock& rhs);
        Clock& operator<(const Clock& rhs);
        Clock& operator>(const Clock& rhs);
        Clock& operator==(const Clock& rhs);
        Clock& operator!=(const Clock& rhs);

        int getHour() {
            return hour;
        }

        int getMinutes() {
            return minutes;
        }

        int getSeconds() {
            return seconds;
        }

        void setTime(int hour, int minutes, int seconds) {
            this->hour = hour;
            this->minutes = minutes;
            this->seconds = seconds;
        }

        ~Clock();

    private:
        int hour, minutes, seconds;
};