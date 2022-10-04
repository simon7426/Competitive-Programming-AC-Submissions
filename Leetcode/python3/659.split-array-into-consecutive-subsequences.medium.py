class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        cnt = defaultdict(int)
        nxt = defaultdict(int)
        for num in nums:
            cnt[num]+=1
        for num in nums:
            if cnt[num]==0:
                continue
            elif nxt[num]>0:
                nxt[num]-=1
                nxt[num+1]+=1
            elif cnt[num+1] > 0 and cnt[num+2]>0:
                cnt[num+1]-=1
                cnt[num+2]-=1
                nxt[num+3]+=1
            else:
                return False
            cnt[num]-=1
        return True