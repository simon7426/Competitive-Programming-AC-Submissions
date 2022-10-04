class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        ans = 0
        for key,val in cnt.items():
            rst = k - key
            ans+=min(cnt[rst],val)
        return ans >> 1