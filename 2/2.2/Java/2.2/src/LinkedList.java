public class LinkedList implements List {
    Cell first, current;
    int currentPosition;
    int elementCount;

    public LinkedList() {
        elementCount = 0;
        currentPosition = -1;
        first = current = null;
    }

    public boolean isEmpty() {
        return elementCount == 0;
    }

    public int end() {
        return elementCount;
    }

    public void insert(int value, int position) {
        if (isEmpty()) {
            elementCount++;
            first = current = new Cell();
            currentPosition = 0;
            current.value = value;
            current.next = null;
        } else if (position >= end()) {

            current = first;
            while (current.next != null)
                current = current.next;
            elementCount++;
            current.next = new Cell();
            current.next.next = null;
            current = current.next;
            current.value = value;
            currentPosition = end();

        } else {
            Cell newCell = new Cell();
            newCell.value = value;
            current = first;
            currentPosition = 0;
            while (current.next != null)
            {
                if (currentPosition == position)
                    break;
                current = current.next;
                currentPosition++;
            }
            newCell.next = current.next;
            current.next = newCell;
            current = newCell;
            currentPosition++;
            elementCount++;
        }

    }

    public int locate(int value) {
        current = first;
        currentPosition = 0;
        while (current != null) {
            if (current.value == value)
                return currentPosition;
            current = current.next;
            currentPosition++;
        }
        return end();

    }

    public int retrieve(int position) {
        current = first;
        currentPosition = 0;
        while (current != null) {
            if (currentPosition == position)
                return current.value;
            current = current.next;
            currentPosition++;
        }
        return -1;
    }

    public void del(int position) {
        if (position == 0) {
            current = first.next;
            first = current;
        }
        else if(position >= end())
            return;
        else {
            current = first;
            currentPosition = 0;
            while (current.next != null)
            {
                if (currentPosition == position - 1)
                {
                    if (current.next.next == null)
                    {
                        current.next = null;
                        elementCount--;
                        return;
                    }
                    else
                    {
                        elementCount--;
                        return;
                    }
                }
                current = current.next;
                currentPosition++;
            }
        }
    }

    public int getCurrentPosition()
    {
        return currentPosition;
    }

    public void print(){
        if (!isEmpty())
        {
            for (int i = 0; i < end(); i++)
                System.out.print(retrieve(i));
        }
        System.out.print("\n");
    }

    public int retrieveFromEnd(int k)
    {
        current = first;
        currentPosition = 0;
        while (current != null)
        {
            if (currentPosition + k == end() - 1)
                return current.value;
            current = current.next;
            currentPosition++;
        }
        return -1;
    }
}
