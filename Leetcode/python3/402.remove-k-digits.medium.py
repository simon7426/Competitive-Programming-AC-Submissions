class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        num_len = len(num)
        if num_len == k:
            return '0'
        for n in num:
            while stack and k and stack[-1]>int(n):
                stack.pop()
                k-=1
            if len(stack)==1 and stack[0]==0:
                stack.pop()
            stack.append(int(n))
        while stack and k:
            stack.pop()
            k-=1
        if not stack:
            return '0'
        return ''.join(map(str,stack))