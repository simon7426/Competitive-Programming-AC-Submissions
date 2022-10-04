class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        lastChoice = -1
        queue = [10000001000]
        heapq.heapify(queue)
        for i in range(1,n):
            if heights[i] <= heights[i-1]:
                continue
            cur = heights[i] - heights[i-1]
            if ladders:
                heapq.heappush(queue, cur)
                ladders -= 1
                continue
            lastChoice = heapq.heappop(queue)
            if cur > lastChoice:
                cur, lastChoice = lastChoice, cur
    
            if cur <= bricks:
                bricks -= cur
            else:
                return i - 1
            heapq.heappush(queue, lastChoice)
        return n-1
                