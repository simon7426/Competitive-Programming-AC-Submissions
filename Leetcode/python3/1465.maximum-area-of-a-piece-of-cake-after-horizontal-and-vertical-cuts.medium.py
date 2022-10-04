class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        Mod = 10**9 + 7
        horizontalCuts.sort()
        verticalCuts.sort()
        
        horizontalCuts = [0] + horizontalCuts + [h]
        verticalCuts = [0] + verticalCuts + [w]
        
        hdis = []
        for i in range(1, len(horizontalCuts)):
            hdis.append((horizontalCuts[i] - horizontalCuts[i-1]))
        hdis.sort(reverse = True)
        wdis = []
        for j in range(1, len(verticalCuts)):
            wdis.append((verticalCuts[j] - verticalCuts[j-1]))
        wdis.sort(reverse = True)
        return hdis[0]*wdis[0]%Mod
