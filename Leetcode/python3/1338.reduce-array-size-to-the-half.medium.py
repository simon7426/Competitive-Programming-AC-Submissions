class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        lol = [(val,key) for key,val in cnt.items()]
        lol.sort(reverse=True)
        lim = (len(arr)+1)//2
        ans = 0
        res = 0
        while(res < lim):
            res+=lol[ans][0]
            ans+=1
        return ans