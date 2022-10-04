class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort(reverse=True)
        ans = 0
        i,j = 0, len(people)-1
        while i<=j:
            if i==j:
                ans+=1
                break
            elif people[i]+people[j]<=limit:
                i+=1
                j-=1
            else:
                i+=1
            ans+=1
        return ans