class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        cnt = set()
        se = set()
        ans = 0
        for num in nums:
            target = k + num
            if target in cnt:
                se.add((num, target))
            cnt.add(num)
        return len(se)