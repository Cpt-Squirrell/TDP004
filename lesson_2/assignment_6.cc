struct Element
{
    Element();
    Element(Element* next, int value) : next(next), value(value) {}
    Element* next = nullptr;
    int value = 0;

    // --- Assignment 6
    static Element* findLast(Element* current)
    {
        if (current -> next == nullptr)
            return current;
        else
            return findLast(current -> next);
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

    // --- Assignment 6
    Element* lastVariable = Element::findLast(first);
}