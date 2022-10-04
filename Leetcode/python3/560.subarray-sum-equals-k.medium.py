class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = {
            0: 1
        }
        ans = 0
        sm = 0
        for num in nums:
            sm+=num
            target = sm - k
            if target in cnt:
                ans+=cnt[target]
            if sm in cnt:
                cnt[sm]+=1
            else:
                cnt[sm] = 1
        return ans