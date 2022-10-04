class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        def sortFunc(i):
            return sum(mat[i])
        val = [i for i in range(len(mat))]
        val.sort(key=sortFunc)
        return val[:k]