class MyCircularQueue:

    def __init__(self, k: int):
        self.size = 0
        self.max_size = k
        self._li = [0]*k
        self.front = self.rear = -1

    def enQueue(self, value: int) -> bool:
        # print(value, self.size, self.max_size)
        if self.size == self.max_size:
            return False
        if self.rear == -1:
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.max_size
        self._li[self.rear] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.size == 0:
            return False
        if self.front == self.rear:
            self.front = self.rear = -1
            self.size = 0
            return True
        self.front = (self.front + 1)% self.max_size
        self.size -= 1
        return True

    def Front(self) -> int:
        if self.size:
            return self._li[self.front]
        return -1

    def Rear(self) -> int:
        if self.size:
            return self._li[self.rear]
        return -1

    def isEmpty(self) -> bool:
        return self.size == 0
        

    def isFull(self) -> bool:
        return self.size == self.max_size


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()