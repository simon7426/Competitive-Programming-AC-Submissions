class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = nums
        self.k = k
        heapq.heapify(self.nums)
        while(len(self.nums))>k:
            heapq.heappop(self.nums)
        return

    def add(self, val: int) -> int:
        heapq.heappush(self.nums,val)
        if len(self.nums)>self.k:
            heapq.heappop(self.nums)
        ret = heapq.heappop(self.nums)
        heapq.heappush(self.nums,ret)
        return ret

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)