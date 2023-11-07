# Uppgift 9 - Destruktor i en kedjad lista
Här ser vi hur det skulle se ut om en kedjad lista skulle ha en destruktor som förstör sitt nästa objekt.

## Kod
```c++
struct Element
{
    Element();
    Element(Element* next, int value) : next(next), value(value) {}
    Element* next = nullptr;
    int value = 0;

    Element::~Element()
    {
        delete next;
    }
};

int main()
{
    Element* first = new Element(nullptr, 5);
    Element* second = new Element(nullptr, 9);
    first->next = second;

    Element* third = new Element(nullptr, 8);
    first->next = third;
    first->next->next = second;
}
```

## Stegvis förklaring
Listan är 3 element lång. Om destruktorn körs på första elementet så kommer den att kalla 'delete' på dens nästa element i kedjan vilket kallar på dens destruktor. Den första destruktorn man kör kommer alltså inte vara färdig förrän alla senare destruktorer har körts. Nästa elements destruktor kommer att kalla på sin nästa elements destruktor tills det kommer ett element som inte har ett nästa element i sin 'next'.