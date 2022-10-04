class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-x for x in stones]
        while stones:
            heapq.heapify(stones)
            val1 = -(heapq.heappop(stones))
            if stones:
                val2= -(heapq.heappop(stones))
            else:
                return val1
            target = val1 - val2
            if target:
                heapq.heappush(stones,-target)
        return 0
            