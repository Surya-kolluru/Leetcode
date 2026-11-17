class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        cost = [[0] * n for _ in range(n)]

        for l in range(n):
            for r in range(l + 1, n):
                ln = r - l + 1
                best = n

                for d in range(1, ln):
                    if ln % d:
                        continue

                    cur = 0
                    q = ln // d

                    for x in range(d):
                        for y in range(q // 2):
                            if s[l + x + y * d] != s[l + x + (q - 1 - y) * d]:
                                cur += 1

                    best = min(best, cur)

                cost[l][r] = best

        inf = 10**9
        dp = [[inf] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for p in range(1, k + 1):
            for i in range(2 * p, n + 1):
                for j in range(2 * (p - 1), i - 1):
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1])

        return dp[n][k]