#include <stdexcept>
#include <iostream>
#include "sorted_list.h"

Sorted_List::Sorted_List() {};
Sorted_List::Sorted_List(const Sorted_List& other)
{
    if (other.root != nullptr)
    {
        Link* currentLink = root;
        Link* otherLink = other.root;
        Link* previousLink = nullptr;
        while (otherLink != nullptr)
        {
            if (previousLink == nullptr)
                currentLink = new Link(otherLink->value);
            else
                currentLink = new Link(previousLink, otherLink->value);
            otherLink = otherLink->p_next;
            previousLink = currentLink;
            currentLink = currentLink->p_next;
        }
    }
}

Sorted_List::Sorted_List(Sorted_List&& other)
{   // Steal 'other's 'root'
    root = other.root;
    other.root = nullptr;
};

bool Sorted_List::is_empty() const
{ return size() == 0 ? true : false; };

int Sorted_List::size() const
{
    if (root == nullptr)
        return 0;
    
    int size = 1;
    Link* currentLink = root;
    while (currentLink->p_next != nullptr)
    {
        size++;
        currentLink = currentLink->p_next;        
    }
    return size;
};

void Sorted_List::insert(int value) {
    if (root == nullptr)
        root = new Link(value);
    else
        root -> insert(value);
}

void Sorted_List::remove(int index)
{
    if (root == nullptr)
        return;
    
    Link* linkBeforeDeletion = root;
    for (int i = 0; i < index; i++)
        { linkBeforeDeletion = linkBeforeDeletion->p_next; };
        
    if (linkBeforeDeletion == nullptr)
        return;
    
    if (linkBeforeDeletion == root)
    {
        if (root->p_next == nullptr)
        {
            delete root;
            root = nullptr;
        } else {
            Link* newRoot = root->p_next;
            root->p_next = nullptr;
            delete root;
            root = newRoot;
        }
    }
    else
    {
        if (linkBeforeDeletion->p_next != nullptr)
        {
            linkBeforeDeletion->p_next = linkBeforeDeletion->p_next->p_next; // Skip the link to be deleted
            linkBeforeDeletion->p_next->p_next = nullptr; // Disassociate the link to be deleted from the list
        }
        delete linkBeforeDeletion->p_next; // Delete the link
    }
};

int Sorted_List::fetch(int index) const
{
    if (root == nullptr)
        throw std::out_of_range("Tried to fetch an item on an empty list");
    Link* indexedLink = root;
    for (int i = 0; i < index; i++) {
        if (indexedLink -> p_next == nullptr)
            throw std::out_of_range("Tried to fetch an item outside the range of the list");
        indexedLink = indexedLink->p_next;
    }
    return indexedLink->value;
}

void Sorted_List::clear()
{
    delete root;
    root = nullptr;
}

Sorted_List& Sorted_List::operator=(const Sorted_List& rhs)
{
    delete root; // Delete the current list
    Sorted_List tempList{rhs};
    root = tempList.root;
    tempList.root = nullptr;
    return *this;
}

bool Sorted_List::operator==(const Sorted_List& rhs) const
{
    for (int index = 0;
        (getLink(index) != nullptr && rhs.getLink(index) != nullptr) ||
        (getLink(index) == nullptr && rhs.getLink(index) == nullptr);
        index++)
    {
        if (getLink(index) == nullptr || rhs.getLink(index) == nullptr)
            return true;
        else if (getLink(index)->value != rhs.getLink(index)->value)
            return false;
    }
    return false;
}

Sorted_List::Link::Link(Link* previous, int value) : p_next(previous->p_next), value(value)
{ if (previous != nullptr) previous->p_next = this; };

Sorted_List::Link::~Link() { delete p_next; };

void Sorted_List::Link::insert(int value)
{
    if (p_next == nullptr)
        p_next = new Link(this, value);
    else if (value > p_next->value)
        p_next = new Link(this, value);
    else p_next->insert(value);
}

Sorted_List::Link::Link(int value) : value(value) {};

Sorted_List::Link* Sorted_List::getLink(int depth) const
{
    Link* currentLink = root;
    for (int index = 0; index < depth; index++)
    {
        if (currentLink == nullptr)
            throw std::out_of_range("Tried to get a link outside the bounds of the list");
        currentLink = currentLink->p_next;
    }
    return currentLink;
}

bool Sorted_List::validateOrder() const
{
    Link* currentLink = root;
    int lastValue = currentLink->value;
    while (currentLink != nullptr) {
        currentLink = currentLink->p_next;
        if (lastValue > currentLink->value)
            return false;
        lastValue = currentLink->value;
    }
    return true;
}

void Sorted_List::print() const
{
    Link* currentLink = root;
    while (currentLink != nullptr)
    {
        std::cout << currentLink->value << ' ';
        currentLink = currentLink->p_next;
    }
    std::cout << std::endl;
}