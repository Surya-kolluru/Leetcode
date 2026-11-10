class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn = prices[0]
        ans = 0

        for pri in prices:
            mn = min(mn, pri)
            ans = max(ans, pri - mn)

        return ans