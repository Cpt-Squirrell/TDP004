#include <string>
#pragma once

// Komplettering: Era .h filer bör ej innehålla några implementationer utan endast deklarationer.
// Klar

// Komplettering: Använd const för parametrar som ej bör ändras i ett funktionsanrop.
// Klar

// Komplettering: Deklarera medlemsfunktioner som inte ändrar på objektets medlemsvariabler som const för att de ska gå att använda med const versioner av objektet.
// Klar

// Komplettering: När ni definierar konstruktorn vill vi att ni använder medlemsinitieringslistan i så stor utsträckning som möjligt istället för att tilldela medlemsvariablerna i konstruktorns funktionskropp. 
// Klar

// Komplettering: Upprepa inte sticky manipulators.
// Klar

// Komplettering: Ni har i er klass deklarerat ett par variabler som static const det är inte nödvändigtvis fel men inget vi har gått igenom så jag vill att ni lägger en kommentar om anledningen till att ni valt att göra på detta sättet så vi kan göra en bedömning om rimligheten i det hela och säkerställa att er förståelse är korrekt.
// Klar

class Clock 
{
    public:
        Clock();
        Clock(const int hour, const int minutes, const int seconds);
        Clock(const std::string& time);

        std::string toString(const bool asLatin = false) const;
        Clock& fromString(const std::string& string);

        Clock& operator+=(const int seconds);
        Clock& operator-=(const int seconds);
        Clock  operator+ (const int seconds) const;
        Clock  operator- (const int seconds) const;

        Clock& operator+=(const Clock& rhs);
        Clock& operator-=(const Clock& rhs);
        Clock  operator+ (const Clock& rhs) const;
        Clock  operator- (const Clock& rhs) const;
        
        Clock& operator++();
        Clock& operator--();
        Clock  operator++(const int);
        Clock  operator--(const int);
        bool operator< (const Clock& rhs) const;
        bool operator<=(const Clock& rhs) const;
        bool operator> (const Clock& rhs) const;
        bool operator>=(const Clock& rhs) const;
        bool operator!=(const Clock& rhs) const;
        bool operator==(const Clock& rhs) const;

        int getHour()    const;
        int getMinutes() const;
        int getSeconds() const;

        void setTime(const int hour, const int minutes, const int seconds);

    private:
        void validateTime(); // Handles overflowing numbers (e.g. >= 60 seconds)
        int toSeconds() const; // Converts the clock into seconds from 00:00:00
        int hour, minutes, seconds;

        // Seconds conversions for days, hours, and minutes
        // This is static because they are constant values shared across all classes
        // There is no reason to declare new integers for every instance of the class
        // That would lead to unwieldy use of memory
        // It's const because they are constant integers that hold the number of seconds in each of their use case
        static const int DAY{86400}, HOUR{3600}, MINUTE{60};
};

std::ostream& operator<<(std::ostream& lhs, const Clock& rhs);
std::istream& operator>>(std::istream& lhs, Clock& rhs);
