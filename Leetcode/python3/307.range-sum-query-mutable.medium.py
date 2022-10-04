class NumArray:

    def __init__(self, nums: List[int]):
        self.sm = [0]*(len(nums)+2)
        self.nums = nums
        for (i,num) in enumerate(nums):
            index=i+1
            while(index<=len(self.nums)):
                self.sm[index]+=num
                index = index + (index & (-index))

    def update(self, index: int, val: int) -> None:
        val = val - self.nums[index]
        self.nums[index] += val
        index+=1
        while(index<=len(self.nums)):
            self.sm[index]+=val
            index = index + (index & (-index))
    
    def sumBegin(self, end: int) -> int:
        end+=1
        if end<=0:
            return 0
        ret = 0
        while(end>0):
            ret+=self.sm[end]
            end =end - (end & (-end))
        return ret

    def sumRange(self, left: int, right: int) -> int:
        return self.sumBegin(right) - self.sumBegin(left-1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)