class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m*n != len(original):
            return []
        ans = []
        for i in range(m):
            tmp = []
            for j in range(n):
                tmp.append(original[n*i+j])
            ans.append(tmp)
        return ans