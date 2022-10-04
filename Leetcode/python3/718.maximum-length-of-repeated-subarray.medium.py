class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n):
            for j in range(m):
                if nums1[i] == nums2[j]:
                    dp[i][j] = dp[i-1][j-1]+1
        return max(max(row) for row in dp)