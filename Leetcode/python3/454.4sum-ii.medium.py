class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        sm = {}
        for i in nums1:
            for j in nums2:
                if i+j in sm:
                    sm[i+j] += 1
                else:
                    sm[i+j] = 1
        ans = 0
        for i in nums3:
            for j in nums4:
                if -1 * (i+j) in sm:
                    ans+= sm[-1 * (i+j)]
        return ans