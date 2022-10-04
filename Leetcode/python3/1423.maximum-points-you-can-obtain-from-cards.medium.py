class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        preS = [0]
        sm =0
        for i in cardPoints:
            sm += i
            preS.append(sm)
        sufS = [0]
        sm = 0
        for i in cardPoints[::-1]:
            sm+=i
            sufS.append(sm)
        i = k
        j = 0
        ans = preS[k-1]
        while(i):
            ans = max(ans, preS[i]+sufS[j])
            i-=1
            j+=1
        ans = max(ans, sufS[k])
        return ans