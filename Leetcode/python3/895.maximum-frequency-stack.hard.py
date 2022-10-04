class FreqStack:

    def __init__(self):
        self.index = 0
        self.q = []
        self.m = collections.defaultdict(int)

    def push(self, val: int) -> None:
        self.m[val] +=1
        heapq.heappush(self.q, (-self.m[val], -self.index, val))
        self.index +=1

    def pop(self) -> int:
        val = heapq.heappop(self.q)[2]
        self.m[val] -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()