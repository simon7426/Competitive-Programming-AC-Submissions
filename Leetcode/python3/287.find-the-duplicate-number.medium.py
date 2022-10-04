class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0, 0
        check = 0
		
        while True:
            slow = nums[ slow ]
            fast = nums[ nums[fast] ]
            if slow == fast:
                break
        while True:
            slow = nums[ slow ]
            check = nums[ check ]
            if slow == check:
                break
        
        return check