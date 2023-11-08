struct Element
{
    Element* next = this;
    int value = 5;
};

int main()
{
    Element* first = new Element;

    // Old
    (*first->next).next->value = 10;
    (*first->next).next->next = nullptr;

     // New
     first->value = 10;
     first->next = nullptr;
}