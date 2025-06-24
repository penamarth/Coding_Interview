#include <iostream>

class List {
public:
    virtual bool isEmpty() = 0;
    virtual void insert(int value, int position) = 0;
    virtual int locate(int value) = 0;
    virtual int retrieve(int position) = 0;
    virtual void print() = 0;
    virtual void del(int position) = 0;
    virtual int end() = 0;
    virtual int getCurrentPosition() = 0;
    virtual ~List() {};
};

struct Cell
{
    int value;
    Cell* next;
};

class PointerList : public List
{
    Cell* first, *current;
    int currentPosition;
    int elementCount;

public:
    PointerList() {
        elementCount = 0;
        currentPosition = -1;
        first = current = nullptr;
    }
    ~PointerList() {
        current = first;
        while (current != nullptr)
        {
            Cell* tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    bool isEmpty() {
        return elementCount == 0;
    }
    int end()
    {
        return elementCount;
    }

    void insert(int value, int position) {
        if (isEmpty()) {
            elementCount++;
            first = current = new Cell();
            currentPosition = 0;
            current->value = value;
            current->next = nullptr;
        }
        else if (position >= end())
        {
            current = first;
            while (current->next != nullptr)
                current = current->next;
            elementCount++;
            current->next = new Cell();
            current->next->next = nullptr;
            current = current->next;
            current->value = value;
            currentPosition = end();
        }
        else
        {
            Cell* newCell = new Cell();
            newCell->value = value;
            current = first;
            currentPosition = 0;
            while (current->next != nullptr)
            {
                if (currentPosition == position)
                    break;
                current = current->next;
                currentPosition++;
            }
            newCell->next = current->next;
            current->next = newCell;
            current = newCell;
            currentPosition++;
            elementCount++;
        }

    }
    int locate(int value) {
        current = first;
        currentPosition = 0;
        while (current != nullptr)
        {
            if (current->value == value)
                return currentPosition;
            current = current->next;
            currentPosition++;
        }
        return end();
    }
    int retrieve(int position) {
        current = first;
        currentPosition = 0;
        while (current != nullptr)
        {
            if (currentPosition == position)
                return current->value;
            current = current->next;
            currentPosition++;
        }
        return -1;
    }
    void del(int position) {
        if (position == 0)
        {
            current = first->next;
            delete first;
            first = current;
        }
        else if (position >= end())
            return;
        else
        {
            current = first;
            currentPosition = 0;
            while (current->next != nullptr)
            {
                if (currentPosition == position - 1)
                {
                    if (current->next->next == nullptr)
                    {
                        delete current->next;
                        current->next = nullptr;
                        elementCount--;
                        return;
                    }
                    else
                    {
                        Cell* toDelete = current->next;
                        elementCount--;
                        current->next = toDelete->next;
                        delete toDelete;
                        return;
                    }
                }
                current = current->next;
                currentPosition++;
            }
        }
    }

    int getCurrentPosition()
    {
        return currentPosition;
    }

    void print() {
        if (!isEmpty())
        {
            for (int i = 0; i < end(); i++)
                std::cout << retrieve(i);
        }
        std::cout << std::endl;
    }

    void deleteCenter() {
        del(elementCount / 2);
    }
};



int main()
{
    List* L = new PointerList();
    L->insert(1, 0);
    L->insert(2, L->end());

    L->insert(3, L->end());
    L->insert(4, L->end());
    L->insert(5, L->end());
    L->insert(6, L->end());
    L->insert(7, L->end());

    L->print();

    ((PointerList*)L)->deleteCenter();

    L->print();
}