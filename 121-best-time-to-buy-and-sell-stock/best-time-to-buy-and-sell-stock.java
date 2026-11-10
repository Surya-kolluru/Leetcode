class Solution {
    public int maxProfit(int[] prices) {
        int min = prices[0];
        int ans = 0;

        for (int pri : prices) {
            min = Math.min(min, pri);
            ans = Math.max(ans, pri - min);
        }

        return ans;
    }
}