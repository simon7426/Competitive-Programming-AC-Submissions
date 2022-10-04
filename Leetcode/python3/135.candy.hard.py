class Solution:
    def candy(self, ratings: List[int]) -> int:
        if len(ratings)<=1:
            return len(ratings)
        top = bot = high = 0
        ans = 1
        for i in range(1,len(ratings)):
            if ratings[i-1]<ratings[i]:
                top+=1
                high = top
                ans += 1 + top
                bot = 0
            elif ratings[i-1] > ratings[i]:
                bot+=1
                ans+=1+bot-(1 if high >=bot else 0)
                top = 0
            else:
                top = high = bot = 0
                ans +=1
        return ans