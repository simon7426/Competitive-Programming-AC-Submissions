class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes = sorted(boxTypes, key = lambda x:x[1], reverse = True)
        res = 0
        for num, unit in boxTypes:
            if truckSize >= num:
                truckSize -= num
                res += num*unit
            else:
                return res + truckSize*unit
        return res