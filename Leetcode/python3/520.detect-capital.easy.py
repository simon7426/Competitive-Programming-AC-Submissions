class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        def isCap(let):
            if let>='A' and let<='Z':
                return True
            return False
        
        n = len(word)
        if n==1:
            return True
        if isCap(word[0]):
            if isCap(word[1]):
                for let in word:
                    if not isCap(let):
                        return False
                return True
            else:
                for let in word[1:]:
                    if isCap(let):
                        return False
                return True
        else:
            for let in word:
                if isCap(let):
                    return False
            return True