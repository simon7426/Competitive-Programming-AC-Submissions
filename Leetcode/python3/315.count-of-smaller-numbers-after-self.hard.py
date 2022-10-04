class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        result = []
        
        sorted_nums = []
        
        for num in reversed(nums):
            index = bisect.bisect_left(sorted_nums, num)
            result.insert(0, index)
            sorted_nums.insert(index, num)
                    
        return result