class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        cnt = Counter(arr)
        print(cnt)
        ans = 0
        MOD = 10**9+7
        for x in cnt:
            for y in cnt:
                if x>y:
                    continue
                z = target - x - y
                if y<=z and z in cnt:
                    
                    if x == y == z:
                        ans+= cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) // 6
                    elif x == y:
                        ans+= cnt[x] * (cnt[x] - 1) * cnt[z] // 2
                    elif x == z:
                        ans+= cnt[x] * cnt[y] * (cnt[x] - 1) // 2
                    elif y == z:
                        ans+= cnt[x] * cnt[y] * (cnt[y] - 1) // 2
                    else:
                        ans+= cnt[x] * cnt[y] * cnt[z]
                    print(x,y,z,ans)
        return ans%MOD