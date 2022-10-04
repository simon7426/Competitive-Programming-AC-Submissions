class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        k,x = x,k
        if x == 0:
            return 0
        tmp = []
        mnVal = 100010
        mnI = 0
        for i,el in enumerate(arr):
            xx = abs(k-el)
            if xx < mnVal:
                mnVal = xx
                mnI = i
            tmp.append(xx)
        x -= 1
        l = mnI-1
        r = mnI+1
        ln = len(arr)
        while(x):
            if l>=0 and r<ln:
                if tmp[l]<=tmp[r]:
                    l-=1
                    
                else:
                    r+=1
            elif l>=0:
                l-=1
            elif r<ln:
                r+=1
            else:
                break
            x-=1
        return [arr[val] for val in range(l+1,r)]