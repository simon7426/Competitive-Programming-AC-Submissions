class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cnt = {}
        for idx,val in enumerate(nums):
            if val in cnt:
                cnt[val].append(idx)
            else:
                cnt[val]=[]
                cnt[val].append(idx)
        for idx, val in enumerate(nums):
            if target-val == val:
                if len(cnt[val])>1:
                    return [cnt[val][0],cnt[val][1]]
            elif target-val in cnt:
                return [cnt[val][0],cnt[target-val][0]]
            