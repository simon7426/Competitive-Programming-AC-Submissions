class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(list)
        for u,v in connections:
            graph[u].append(v)
            graph[v].append(u)
        
        dis, low, time, ans = [0]*n, [0]*n, [1], []
        def dfs(curr, pre):
            dis[curr] = low[curr] = time[0]
            time[0]+=1
            for node in graph[curr]:
                if not dis[node]:
                    dfs(node, curr)
                    low[curr] = min(low[curr], low[node])
                elif node!=pre:
                    low[curr] = min(low[curr], dis[node])
                if low[node]>dis[curr]:
                    ans.append([curr, node])
        dfs(0,-1)
        return ans