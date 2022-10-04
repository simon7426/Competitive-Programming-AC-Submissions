class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        pa = [i for i in range(26)]
        def findPa(val):
            if val == pa[val]:
                return val
            pa[val] = findPa(pa[val])
            return pa[val]
        def union(xx, yy):
            pxx = findPa(xx)
            pyy = findPa(yy)
            if pxx > pyy:
                pxx,pyy = pyy,pxx
            pa[pyy] = pxx
        
        for eq in equations:
            a = ord(eq[0]) - ord('a')
            b = ord(eq[3]) - ord('a')
            if eq[1] == '=':
                union(a,b)
        for eq in equations:
            a = ord(eq[0]) - ord('a')
            b = ord(eq[3]) - ord('a')
            if eq[1] == '!':
                if findPa(a) == findPa(b):
                    return False
        return True