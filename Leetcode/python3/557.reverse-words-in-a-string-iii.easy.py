class Solution:
    def reverseWords(self, s: str) -> str:
        current_word = ''
        start = 0
        for x in range(len(s)):
            index = s[x]
            if index == ' ':
                beginning = s[:start]
                end = s[x:]
                s = beginning + current_word + end
                start = x + 1
                current_word = ''
            else:
                current_word = index + current_word
        s = s[:start] + current_word
        return s