class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        pat = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        ans = {}
        for word in words:
            tmp = ""
            for let in word:
                tmp+=pat[ord(let)-ord('a')]
            ans[tmp] = 1
        return len(ans)