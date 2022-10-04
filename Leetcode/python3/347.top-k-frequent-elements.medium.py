class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        ans = [(val, key) for key, val in cnt.items()]
        ans.sort(reverse=True)
        ret = [ans[i][1] for i in range(k)]
        return ret