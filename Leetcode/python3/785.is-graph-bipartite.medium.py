class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def dfs(node, c):
            col[node] = c
            for v in graph[node]:
                if col[v]==c:
                    return False
                if col[v] == 0 and not dfs(v,-c):
                    return False
            return True
        n = len(graph)
        col = [0]*n
        for i in range(n):
            if col[i]==0:
                if not dfs(i,1):
                    return False
        return True