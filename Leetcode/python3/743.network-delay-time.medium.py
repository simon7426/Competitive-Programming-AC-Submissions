class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list)
        for u,v,w in times:
            if u==v:
                return -1
            graph[u].append((v,w))
        if k not in graph:
            return -1
        priority_queue = [(0,k)]
        dict = {}
        while priority_queue:
            dis, node = heapq.heappop(priority_queue)
            if node in dict:
                continue
            dict[node] = dis
            for target, distance in graph[node]:
                if target not in dict:
                    heapq.heappush(priority_queue, (dis+distance, target))
        return max(dict.values()) if len(dict)==n else -1