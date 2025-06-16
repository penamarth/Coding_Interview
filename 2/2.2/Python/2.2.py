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
        self.next = None
class PointerList(List):
    def __init__(self):
        self.first = None
        self.current = None
        self.currentPosition = -1
        self.elementCount = 0
    def isEmpty(self) -> bool:
        return self.elementCount == 0
    def end(self) -> int:
         return self.elementCount
    def insert(self, value: int, position: int):
        if self.isEmpty():
            self.elementCount = self.elementCount + 1
            self.first = self.current = Cell()
            self.currentPosition = 0
            self.current.value = value
            self.current.next = None
        elif position >= self.end():
            self.current = self.first
            while self.current.next != None:
                self.current = self.current.next
            self.elementCount = self.elementCount + 1
            self.current.next = Cell()
            self.current.next.next = None
            self.current = self.current.next
            self.current.value = value
            self.currentPosition = self.end()
        else:
            newCell = Cell()
            newCell.value = value
            self.current = self.first
            self.currentPosition = 0
            while self.current.next != None:
                if self.currentPosition == position:
                    break
                self.current = self.current.next
                self.currentPosition = self.currentPosition + 1

            newCell.next = self.current.next
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
        elif position >= self.end():
            return
        else:
            self.current = self.first
            self.currentPosition = 0
            while self.current.next != None:
                if self.currentPosition == position - 1:
                    if self.current.next.next == None:
                        self.current.next = None
                        self.elementCount = self.elementCount - 1
                        return
            else:
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

    def retrieveFromEnd(self, k: int)->int:
        self.current = self.first
        self.currentPosition = 0
        while self.current != None:
            if self.currentPosition + k == self.end() - 1:
                return self.current.value
            self.current = self.current.next
            self.currentPosition = self.currentPosition + 1
        return -1


if __name__ == '__main__':

        L = PointerList()
        L.insert(1, 0)
        L.insert(2, L.end())
        L.insert(3, L.end())
        L.insert(4, L.end())
        L.insert(5, L.end())
        L.insert(6, L.end())
        L.insert(7, L.end())

        L.printList()

        print(str(L.retrieveFromEnd(0)))
        print(str(L.retrieveFromEnd(1)))
        print(str(L.retrieveFromEnd(2)))
        print(str(L.retrieveFromEnd(3)))
        print(str(L.retrieveFromEnd(4)))
        print(str(L.retrieveFromEnd(5)))
        print(str(L.retrieveFromEnd(6)))
        print(str(L.retrieveFromEnd(7)))