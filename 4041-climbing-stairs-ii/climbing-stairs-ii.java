class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n + 1];
        java.util.Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = Math.max(0, i - 3); j < i; j++) {
                dp[i] = Math.min(dp[i],
                    dp[j] + costs[i - 1] + (i - j) * (i - j));
            }
        }

        return dp[n];
    }
}