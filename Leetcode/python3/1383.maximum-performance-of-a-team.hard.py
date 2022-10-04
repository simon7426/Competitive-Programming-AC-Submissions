class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10**9 + 7

        pq = []
        engs = list(zip(speed, efficiency))
        engs.sort(key=lambda tup:-tup[1])
        ans = 0
        tops = 0
        for eng in engs:
            min_efficiency = eng[1]
            if len(pq) == k:
                if pq[0] < eng[0]: 
                    bots = heapq.heappop(pq)
                    heapq.heappush(pq, eng[0])
                    tops = tops - bots + eng[0]
            else:
                heapq.heappush(pq, eng[0])
                tops += eng[0]
            ans = max(ans, tops*min_efficiency)
        return ans % MOD