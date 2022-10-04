class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        s1 = len(v1)
        s2 = len(v2)
        swap = 1
        if s1 > s2:
            v1, v2 = v2, v1
            s1, s2 = s2, s1
            swap = -1
        while(s1!=s2):
            v1.append('0')
            s1+=1
        for i in range(s1):
            x = int(v1[i])
            y = int(v2[i])
            if x!=y:
                if x>y:
                    return 1 * swap
                else:
                    return -1 * swap
        return 0