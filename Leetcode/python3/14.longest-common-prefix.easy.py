class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        cur = 0
        wrd_len = 200
        for word in strs:
            wrd_len = min(wrd_len, len(word))
        not_match = False
        j=0
        while(j<wrd_len):
            cur_let = strs[0][j]
            for i in range(len(strs)):
                if strs[i][j]!=cur_let:
                    not_match = True
                    break
            if not_match != False:
                break
            j+=1
        return strs[0][0:j]