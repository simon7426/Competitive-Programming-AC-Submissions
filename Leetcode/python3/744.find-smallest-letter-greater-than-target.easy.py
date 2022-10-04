class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        lo=0
        hi=len(letters)
        while(lo<hi):
            mid = (lo+hi)>>1
            if(letters[mid]<=target):
                lo = mid+1
            else:
                hi = mid
        if lo>=len(letters):
            lo = 0
        return letters[lo]