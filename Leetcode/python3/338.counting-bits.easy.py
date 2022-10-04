class Solution:
    def countBits(self, n: int) -> List[int]:
        def count_one(val):
            cnt = 0
            while val:
                cnt+=1
                val = val&(val-1)
            return cnt
        ans = []
        for i in range(n+1):
            ans.append(count_one(i))
        return ans