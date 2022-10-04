class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ans = 0
        val = 0
        se = set()
        for i in range(30,-1,-1):
            val |= (1<<i)
            new_ans = ans | (1<<i)
            for num in nums:
                se.add(num & val)
            for item in se:
                if new_ans ^ item in se:
                    ans = new_ans
                    break
            se.clear()
        return ans