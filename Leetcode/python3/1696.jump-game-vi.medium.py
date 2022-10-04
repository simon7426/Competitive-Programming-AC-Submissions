class Solution:
    def maxResult(self, A, k):
        pq = [(0, -k)]

        for i, a in enumerate(A):

            while i - pq[0][1] > k: heappop(pq)

            a -= pq[0][0]

            heappush(pq, (-a, i))

        return a