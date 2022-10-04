class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        res = []
        heap = [0]
        g = sorted(i  for l,r,h in buildings for i in [[l,0,-h], [r,1,-h]]) 
        for l,k,h in g:
            if k == 0:
                if h < heap[0]: res.append([l,-h]) 
                bisect.insort(heap, h)
            else:
                heap.remove(h) 
                if h < heap[0]:
                    if l == res[-1][0]:res.pop()
                    res.append([l,-heap[0]])
        return res
   