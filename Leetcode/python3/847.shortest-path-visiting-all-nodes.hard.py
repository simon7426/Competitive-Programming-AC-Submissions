class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        vis = set()
        queue = deque()
        n = len(graph)
        target = (1<<n)-1
        for i in range(n):
            queue.append((i, 1<<i))
        ans = 0
        while(queue):
            for _ in range(len(queue)):
                node, state = queue.popleft()
                if state == target:
                    return ans
                if (node,state) in vis:
                    continue
                vis.add((node,state))
                for neighbor in graph[node]:
                    queue.append((neighbor, state | (1<<neighbor)))
            ans+=1
        return -1