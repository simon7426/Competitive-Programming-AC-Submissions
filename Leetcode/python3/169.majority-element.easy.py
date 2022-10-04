class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cand = -1
        cnt = 0
        for n in nums:
            if n!=cand and cnt==0:
                cand=n
                cnt+=1
            elif n!=cand:
                cnt-=1
            elif n==cand:
                cnt+=1
        return cand