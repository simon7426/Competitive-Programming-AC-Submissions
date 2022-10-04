class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        stations.append([target,0])
        skip = []
        ans = 0
        prev = 0
        fuel = startFuel
        for pos, gas in stations:
            dis = pos - prev
            if fuel<dis:
                while skip and fuel < dis:
                    fuel += -heapq.heappop(skip)
                    ans+=1
                if fuel < dis:
                    return -1
            fuel -= dis
            heapq.heappush(skip, -gas)
            prev = pos
        return ans