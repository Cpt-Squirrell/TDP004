# Abstraction
Abstraction (abstraktion) handlar om att göra mer med mindre. När man abstraktifierar kod så försöker man generalisera vad koden kan arbeta med. Ett exempel på detta inom C++ är standard sorteringsfunktionen `qsort`, som tar in en void-pointer (vilken datatyp som helst) och ett funktionsargument som förklarar för funktionen hur den ska sortera datatypen.

## Exempel på dålig abstraktifiering
Detta är inte bra abstraktifiering (ingen abstraktifiering) för att funktionen hanterar enbart ett enda utfall. Du behöver skriva fler funktioner av samma art för att hantera fler fall.

```c++
bool check_less_than_5(float value)
{
    if (value < 5)
    {
        std::cout << "sant" << std::endl;
        return true;
    }
    return false;
};
```

## Exempel på bättre abstraktifiering
Här är ungefär samma funktion men som tar in ett extra flyttal som gränsvärde och ett meddelande att skriva ut om jämförelsen är lyckad.

```c++
bool check_less(float value, float check_value, std::string message)
{
    if (value < check_value)
    {
        std::cout << message << std::endl;
        return true;
    }
    return false;
};
```