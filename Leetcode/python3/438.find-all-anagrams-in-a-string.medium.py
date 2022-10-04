class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_cnt = [0] * 26
        s_cnt = [0] * 26
        p_len = len(p)
        s_len = len(s)
        if p_len > s_len:
            return []
        for i in p:
            p_cnt[ord(i)-ord('a')]+=1
        for i in range(p_len):
            s_cnt[ord(s[i])-ord('a')]+=1
            
        def match(arr_a, arr_b):
            for i in range(26):
                if arr_a[i]!=arr_b[i]:
                    return False
            return True
        ans = []
        for i in range(p_len, s_len):
            if match(p_cnt, s_cnt):
                ans.append(i-p_len)
            s_cnt[ord(s[i-p_len])-ord('a')] -= 1
            s_cnt[ord(s[i])-ord('a')] += 1
        if match(p_cnt, s_cnt):
            ans.append(s_len-p_len)
        return ans