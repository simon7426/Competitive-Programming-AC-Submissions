class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n==0:
            return []
        ans = []
        first = last = str(nums[0])
        for i in range(1,n):
            if nums[i] - 1 == nums[i-1]:
                continue
            else:
                last = str(nums[i-1])
                if first == last:
                    ans.append(first)
                else:
                    ans.append(f"{first}->{last}")
                first = str(nums[i])
        last = str(nums[n-1])
        if first == last:
            ans.append(first)
        else:
            ans.append(f"{first}->{last}")
        return ans