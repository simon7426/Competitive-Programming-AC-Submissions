class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        vis = set()
        ans = {}
        graph = defaultdict(list)
        comp = defaultdict(list)
        ind = 0
        n = len(s)
        for a,b in pairs:
            graph[a].append(b)
            graph[b].append(a)
        def dfs(val, i):
            vis.add(val)
            comp[i].append(val)
            for y in graph[val]:
                if y not in vis:
                    dfs(y,i)
        
        for i in range(n):
            if i not in vis:
                dfs(i, ind)
                ind+=1
        
        for val in comp.values():
            for i,l in zip(sorted(val), sorted(s[t] for t in val)):
                ans[i] = l
        return "".join(ans[i] for i in range(n))