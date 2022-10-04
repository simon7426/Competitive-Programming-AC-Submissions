class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        l,r = 0, len(tokens) - 1
        ans = 0
        ret = 0
        while l<=r:
            if power>=tokens[l]:
                power-=tokens[l]
                ans+=1
                l+=1
            elif ans and power < tokens[r]:
                power+=tokens[r]
                r-=1
                ans-=1
            else:
                break
            ret = max(ans,ret)
        return ret