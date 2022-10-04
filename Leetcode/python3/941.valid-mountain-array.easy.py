class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        mx = -1
        mx_pos = 0
        for i in range(len(arr)):
            if arr[i]>mx:
                mx = arr[i]
                mx_pos = i
        if len(arr)<3 or mx_pos == 0 or mx_pos==len(arr)-1:
            return False
        for i in range(1,mx_pos+1):
            if arr[i]<=arr[i-1]:
                return False
        for i in range(mx_pos+1,len(arr)):
            if arr[i]>=arr[i-1]:
                return False
        return True