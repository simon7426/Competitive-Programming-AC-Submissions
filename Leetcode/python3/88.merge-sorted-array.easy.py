class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[n:] = nums1[0:m]
        i = i1 = i2 = 0
        while i1<m and i2<n:
            if nums1[i1+n]<nums2[i2]:
                nums1[i]=nums1[i1+n]
                i+=1
                i1+=1
            else:
                nums1[i]= nums2[i2]
                i+=1
                i2+=1
        while i1<m:
            nums1[i]=nums1[i1+n]
            i+=1
            i1+=1
        while i2<n:
            nums1[i]= nums2[i2]
            i+=1
            i2+=1
