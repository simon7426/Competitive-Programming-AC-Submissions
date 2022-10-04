class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        mp = {}
        if k==0:
            return False
        for i in range(len(nums)):
            bucket = nums[i] // (t+1)
            if bucket in mp:
                return True
            if bucket+1 in mp:
                if abs(i-mp[bucket+1])<=k and abs(nums[i] - nums[mp[bucket+1]])<=t:
                    return True
            if bucket-1 in mp:
                if abs(i-mp[bucket-1])<=k and abs(nums[i] - nums[mp[bucket-1]])<=t:
                    return True
            if i-k>=0:
                del mp[nums[i-k]//(t+1)]
            mp[bucket] = i
        return False
                    