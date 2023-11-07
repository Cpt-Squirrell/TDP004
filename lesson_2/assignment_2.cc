struct thing
{
    thing* next = this;
    int value = 5;
};

int main()
{
    thing* first = new thing;

    // Old
    (*first->next).next->value = 10;
    (*first->next).next->next = nullptr;

     // New
     first->value = 10;
     first->next = nullptr;
}