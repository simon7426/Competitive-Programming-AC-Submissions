class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        t_cnt = [0] * 26
        s_cnt = [0] * 26
        t_len = len(t)
        s_len = len(s)
        if t_len != s_len:
            return False
        for i in t:
            t_cnt[ord(i)-ord('a')]+=1
        for i in s:
            s_cnt[ord(i)-ord('a')]+=1
            
        def match(arr_a, arr_b):
            for i in range(26):
                if arr_a[i]!=arr_b[i]:
                    return False
            return True
        return match(s_cnt, t_cnt)