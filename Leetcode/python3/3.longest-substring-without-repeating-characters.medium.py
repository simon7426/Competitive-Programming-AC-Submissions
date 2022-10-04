class Solution:

    def lengthOfLongestSubstring(self, s: str) -> int:

        n = len(s)

        ans = 0

        i=0

        j=0

        mp = {}

        while(i<n):

            # print(i,j)

            if s[j] in mp:

                while(s[j] in mp):

                    # print(s[i], mp)

                    del(mp[s[i]])

                    i+=1

            mp[s[j]] = 1

            ans = max(ans,j-i+1)

            j+=1

            if j==n:

                break

        return ans
