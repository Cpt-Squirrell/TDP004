# Uppgift 7 - Minnesläcka
Här ser vi en kod som beskriver en minnesläcka för att funktionen 'insert' byter ut värdet av sin parameter 'e' utan att destruktera den innan. Om inte programmeraren raderar 'e' innan han skickar in 'e' till funktionen kommer det tidigare värdet av 'e' "tappas bort".

```c++
struct Element
{
    Element();
    Element(Element* next, int value) : next(next), value(value) {}
    Element* next = nullptr;
    int value = 0;
};

void insert(Element* e, int i)
{
  e = new Element(e->next, i);
}

int main()
{
    Element* first = new Element(nullptr, 5);
    Element* second = new Element(nullptr, 9);
    first->next = second;

    Element* third = new Element(nullptr, 8);
    first->next = third;
    first->next->next = second;
    
    insert(first, 2);
}
```
