class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        n = len(digits)
        ans = []
        def dfs(cur, let):
            if cur == n:
                ans.append(let)
                return
            for i in dic[digits[cur]]:
                dfs(cur+1, let+i)
        if n:
            dfs(0,"")
        return ans