class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        sm = 0
        for x in nums:
            if not x&1:
                sm+=x
        ans = []
        for query in queries:
            val, index = query
            if nums[index] & 1 and val & 1:
                sm+=nums[index]+val
            elif not nums[index]&1 and not val&1:
                sm+=val
            elif not nums[index]&1 and val & 1:
                sm -= nums[index]
            nums[index]+=val
            ans.append(sm)
        return ans