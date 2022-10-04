def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a%b)

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        nums.reverse()
        gc = gcd(n,k)
        for i in range(gc):
            tmp = nums[i]
            j = i
            while(1):
                nxt = j + k
                if nxt>=n:
                    nxt -= n
                if nxt == i:
                    break
                nums[j] = nums[nxt]
                j = nxt
            nums[j] = tmp
        nums.reverse()