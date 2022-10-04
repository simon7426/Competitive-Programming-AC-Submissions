class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        @lru_cache(None)
        def dp(x, y):
            val = matrix[x][y]
            ret = 1 + max(
                dp(x - 1, y) if x > 0 and val > matrix[x - 1][y] else 0,
                dp(x + 1, y) if x < m - 1 and val > matrix[x + 1][y] else 0,
                dp(x, y - 1) if y > 0 and val > matrix[x][y - 1] else 0,
                dp(x, y + 1) if y < n - 1 and val > matrix[x][y + 1] else 0)
            return ret

        m, n = len(matrix), len(matrix[0])
        return max(dp(x, y) for x in range(m) for y in range(n))
        