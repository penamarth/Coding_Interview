class List:
    def isEmpty(self)->bool:
        pass
    def insert(self, value: int, position: int):
        pass
    def locate(self, value: int) -> int:
        pass
    def retrieve(self, position: int) -> int:
        pass
    def print(self):
        pass
    def delete(self, position: int):
        pass
    def end(self)->int:
        pass
    def getCurrentPosition(self)->int:
        pass
class Cell:
    def __init__(self):
        self.value = None
        self.previous = None
        self.next = None
class PointerList(List):
    def __init__(self):
        self.first = None
        self.current = None
        self.last = None
        self.currentPosition = -1
        self.elementCount = 0
    def isEmpty(self) -> bool:
        return self.elementCount == 0
    def end(self) -> int:
         return self.elementCount
    def insert(self, value: int, position: int):
        if self.isEmpty():
            self.elementCount = self.elementCount + 1
            self.first = self.last = self.current = Cell()
            self.currentPosition = 0
            self.current.value = value
            self.current.next = None
            self.current.previous = None
        elif position >= self.end():
            self.current = self.last
            self.currentPosition = self.end()
            self.last = Cell()
            self.last.value = value
            self.last.next = None
            self.last.previous = self.current
            self.current.next = self.last
            self.elementCount = self.elementCount + 1
            self.current = self.last
        else:
            newCell = Cell()
            newCell.value = value
            newCell.previous = self.current
            newCell.next = self.current.next
            self.current.next.previous = newCell
            self.current.next = newCell
            self.current = newCell
            self.currentPosition = self.currentPosition + 1
            self.elementCount = self.elementCount + 1
    def locate(self, value: int) -> int:
        self.current = self.first
        self.currentPosition = 0
        while (self.current != None):
            if (self.current.value == value):
                return self.currentPosition
            self.current = self.current.next
            self.currentPosition = self.currentPosition + 1
        return self.end()
    def retrieve(self, position: int) -> int:
        self.current = self.first
        self.currentPosition = 0
        while (self.current != None):
            if (self.currentPosition == position):
                return self.current.value
            self.current = self.current.next
            self.currentPosition = self.currentPosition + 1
        return -1
    def delete(self, position: int):
        if position == 0:
            self.current = self.first.next
            self.first = self.current
        else:
            self.current = self.first
            self.currentPosition = 0
            while self.current != None:
                if self.currentPosition == position:
                    if self.current.next == None:
                        self.current = self.current.previous
                        self.currentPosition = self.currentPosition - 1
                        self.elementCount = self.elementCount - 1
                        self.current.next = None
                        return
                    else:
                        self.current.next.previous = self.current.previous
                        self.current.previous.next = self.current.next
                        self.elementCount = self.elementCount - 1
                        return

                self.current = self.current.next
                self.currentPosition = self.currentPosition + 1
    def getCurrentPosition(self)->int:
        return self.currentPosition
    def printList(self):
        if not self.isEmpty():
            for i in range(0, self.end()):
                print(self.retrieve(i))
        print("\n")


def purge(L: List):
    p = 0
    while p != L.end():
        q = p + 1
        while q != L.end():
            if L.retrieve(p) == L.retrieve(q):
                L.delete (q)
            else:
                q = q + 1
        p = p + 1


if __name__ == '__main__':

        L = PointerList()
        L.insert(1, 0)
        L.insert(2, L.end())
        L.insert(2, L.end())
        L.insert(3, L.end())

        L.printList()
        purge(L)

        L.printList()

        L = PointerList()
        L.insert(1, 0)
        L.insert(1, L.end())
        L.insert(2, L.end())
        L.insert(3, L.end())

        L.printList()
        purge(L)

        L.printList()

        L = PointerList()
        L.insert(1, 0)
        L.insert(2, L.end())
        L.insert(3, L.end())
        L.insert(3, L.end())

        L.printList()
        purge(L)

        L.printList()
