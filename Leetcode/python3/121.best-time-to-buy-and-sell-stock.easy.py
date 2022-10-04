class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prices_len = len(prices)
        suff_prices = [x for x in prices]
        for i in range(1,prices_len):
            suff_prices[prices_len-1-i] = max(suff_prices[prices_len-1-i],suff_prices[prices_len-i])
        ans = 0
        for i in range(prices_len):
            ans = max(ans,suff_prices[i]-prices[i])
        return ans