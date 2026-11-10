#include <stdlib.h>
#include <limits.h>

int climbStairs(int n, int* costs, int costsSize) {
    int* dp = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = (i > 3 ? i - 3 : 0); j < i; j++) {
            int d = i - j;
            int val = dp[j] + costs[i - 1] + d * d;

            if (val < dp[i]) {
                dp[i] = val;
            }
        }
    }

    int ans = dp[n];
    free(dp);

    return ans;
}