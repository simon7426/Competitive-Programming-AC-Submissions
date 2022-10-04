class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i=0
        j=0
        k = len(pushed)
        l = len(pushed)
        st = []
        while(i<k and j<l):
            if st and st[-1] == popped[j]:
                st.pop()
                j+=1
            else:
                st.append(pushed[i])
                i+=1
        while(j<l):
            if st and st[-1]==popped[j]:
                st.pop()
                j+=1
            else:
                return False
        return True