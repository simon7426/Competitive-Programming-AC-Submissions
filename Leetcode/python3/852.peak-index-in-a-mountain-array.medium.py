class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        lo = 0
        hi = len(arr)
        if arr[0]>arr[1]:
            return 0
        if arr[hi-1]>arr[hi-2]:
            return hi-1
        for i in range(200):
            mid = (lo+hi)>>1
            if arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]:
                return mid
            if arr[mid]>arr[mid+1] and arr[mid]<arr[mid-1]:
                hi = mid
            if arr[mid]<arr[mid+1] and arr[mid]>arr[mid-1]:
                lo = mid