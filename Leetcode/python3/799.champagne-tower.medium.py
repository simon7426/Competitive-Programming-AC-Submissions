class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        queue = [poured]
        for i in range(query_row):
            tmp = [0] * (len(queue)+1)
            for j in range(len(queue)):
                if queue[j]<=1:
                    continue
                tmp[j] += (queue[j]-1)/2
                tmp[j+1] += (queue[j]-1)/2
            queue = tmp
        return min(queue[query_glass], 1)