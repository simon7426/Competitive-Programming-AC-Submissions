# class Solution:
#     def numSquares(self, n: int) -> int:
#         dp = [2**31]*(n+1)
#         squares = [i**2 for i in range(int(math.sqrt(n))+1)]
# #         for i in range(n+1):
# #             if i in squares:
# #                 dp[i] = 1
# #             else:
# #                 j = 1
# #                 while(j*j<=n):
# #                     dp[i] = min(dp[i], dp[i-j*j]+1)
# #                     j+=1
# #         return dp[n]
#         dp[0] = 0
#         for i in range(1,n+1):
#             for square in squares:
#                 if i < square:
#                     break
#                 dp[i] = min(dp[i], dp[i-square]+1)
#         return dp[n]
class Solution:
    def numSquares(self, n: int) -> int:
        queue = set()
        queue.add(n)
        ans = 0
        while(queue):
            tmp = set()
            ans+=1
            for val in queue:
                i = 1
                while(i*i<=val):
                    new_val = val - i * i
                    if new_val==0:
                        return ans
                    i+=1
                    tmp.add(new_val)
            queue = tmp
        return ans
