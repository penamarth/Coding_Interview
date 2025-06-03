public class LinkedList implements List {
    Cell first, current, last;
    int currentPosition;
    int elementCount;

    public LinkedList() {
        elementCount = 0;
        currentPosition = -1;
        first = current = last = null;
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
            first = last = current = new Cell();
            currentPosition = 0;
            current.value = value;
            current.next = null;
            current.previous = null;
        } else if (position >= end()) {
            current = last;
            currentPosition = end();
            last = new Cell();
            last.value = value;
            last.next = null;
            last.previous = current;
            current.next = last;
            elementCount++;
            current = last;
        } else {
            Cell newCell = new Cell();
            newCell.value = value;
            newCell.previous = current;
            newCell.next = current.next;
            current.next.previous = newCell;
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
        } else {
            current = first;
            currentPosition = 0;
            while (current != null) {
                if (currentPosition == position) {
                    if (current.next == null) {
                        current = current.previous;
                        currentPosition--;
                        elementCount--;
                        current.next = null;
                        return;
                    } else {

                        current.next.previous = current.previous;
                        current.previous.next = current.next;
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

    public void purge() {
        int p, q;
        p = 0;
        while (p != end()) {
            q = p + 1;
            while (q != end()) {
                if (retrieve(p) == retrieve(q))
                    del(q);
                else
                    q++;
            }
            p++;
        }
    }
}
