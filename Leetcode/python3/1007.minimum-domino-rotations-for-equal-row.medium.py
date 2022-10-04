class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def check(n):
            reta = retb = 0
            for i in range(len(tops)):
                if tops[i]!=n and bottoms[i]!=n:
                    return -1
                elif tops[i]!=n:
                    reta+=1
                elif bottoms[i]!=n:
                    retb +=1
            return min(reta,retb)
        ans = check(tops[0])
        if ans!=-1 or tops[0]==bottoms[0]:
            return ans
        return check(bottoms[0])