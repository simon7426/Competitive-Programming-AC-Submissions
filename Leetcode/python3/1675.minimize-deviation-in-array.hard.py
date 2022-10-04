class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        q = []
        for num in nums:
            q.append(-num * 2 if num & 1 else -num)
        ans = float('inf')
        maxv = max(q)
        heapq.heapify(q)
        while(1):
            top = heapq.heappop(q)
            ans = min(ans, maxv-top)
            if top & 1:
                break
            top >>=1
            maxv = max(maxv, top)
            heapq.heappush(q,top)
        return ans