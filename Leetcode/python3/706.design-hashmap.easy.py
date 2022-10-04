class MyHashMap:

    def __init__(self):
        self.arr = [[] for i in range(1<<15)]

    def put(self, key: int, value: int) -> None:
        t = self.get_hash(key)
        for k in self.arr[t]:
            if k[0] == key:
                k[1] = value
                return
        self.arr[t].append([key,value])

    def get(self, key: int) -> int:
        t = self.get_hash(key)
        for k in self.arr[t]:
            if k[0] == key:
                return k[1]
        return -1

    def remove(self, key: int) -> None:
        t = self.get_hash(key)
        for k in self.arr[t]:
            if k[0] == key:
                self.arr[t].remove(k)
                return
    
    def get_hash(self, key: int) -> int:
        return ((100019 * key) & (1<<20) - 1) >> 5


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)