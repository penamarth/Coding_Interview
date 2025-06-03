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
    Cell *previous, *next;
};

class PointerList : public List
{
    Cell *first, *current, *last;
    int currentPosition;
    int elementCount;

public:
    PointerList() {
        elementCount = 0;
        currentPosition = -1;
        first = current = last = nullptr;
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
            first = last = current = new Cell();
            currentPosition = 0;
            current->value = value;
            current->next = nullptr;
            current->previous = nullptr;
        }
        else if (position >= end())
        {
            current = last;
            currentPosition = end();
            last = new Cell();
            last->value = value;
            last->next = nullptr;
            last->previous = current;
            current->next = last;
            elementCount++;
            current = last;
        }
        else
        {
            Cell* newCell = new Cell();
            newCell->value = value;
            newCell->previous = current;
            newCell->next = current->next;
            current->next->previous = newCell;
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
        else
        {
            current = first;
            currentPosition = 0;
            while (current != nullptr)
            {
                if (currentPosition == position)
                {
                    if (current->next == nullptr)
                    {
                        current = current->previous;
                        currentPosition--;
                        elementCount--;
                        delete current->next;
                        current->next = nullptr;
                        return;
                    }
                    else
                    {
                        Cell *toDelete = current;
                        current->next->previous = current->previous;
                        current->previous->next = current->next;
                        elementCount--;
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
    
    void print(){
        if (!isEmpty())
        {
            for (int i = 0; i < end(); i++)
                std::cout << retrieve(i);
        }
        std::cout << std::endl;
    }

};

void purge(List *L)
{
    int p, q;
    p = 0;
    while (p != L->end())
    {
        q = p + 1;
        while (q != L->end())
        {
            if (L->retrieve(p) == L->retrieve(q))
                L->del(q);
            else
                q++;
        }
        p++;
    }
}

int main()
{
    {
        List* L = new PointerList();
        L->insert(1, 0);
        L->insert(2, L->end());
        L->insert(2, L->end());
        L->insert(3, L->end());

        L->print();
        purge(L);

        L->print();
    }

    {
        List* L = new PointerList();
        L->insert(1, 0);
        L->insert(1, L->end());
        L->insert(2, L->end());
        L->insert(3, L->end());

        L->print();
        purge(L);

        L->print();
    }

    {
        List* L = new PointerList();
        L->insert(1, 0);
        L->insert(2, L->end());
        L->insert(3, L->end());
        L->insert(3, L->end());

        L->print();
        purge(L);

        L->print();
    }
}

