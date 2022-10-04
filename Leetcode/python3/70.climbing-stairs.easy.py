steps = [-1 for i in range(50)]
def fun(x):
    if x<0:
        return 0
    if x<=2:
        return x
    if steps[x]==-1:
        steps[x] = fun(x-1)+fun(x-2)
        return steps[x]
    return steps[x]
class Solution:
    def climbStairs(self, n: int) -> int:
        return fun(n)