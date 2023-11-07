struct Element
{
    Element();
    Element(Element* next, int value) : next(next), value(value) {}
    Element* next = nullptr;
    int value = 0;
};

int main()
{
    Element* first = new Element(nullptr, 5);
    Element* second = new Element(nullptr, 9);
    first->next = second;

    Element* third = new Element(nullptr, 8);
    first->next = third;
    first->next->next = second;

    // --- Assignment 5
    Element* lastElement = first;
    while (lastElement -> next != nullptr) {
        lastElement = lastElement -> next;
    }
}