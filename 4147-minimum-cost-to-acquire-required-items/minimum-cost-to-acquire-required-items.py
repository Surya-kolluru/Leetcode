class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        c1 = need1 * cost1 + need2 * cost2

        mn = min(need1, need2)
        c2 = mn * costBoth + (need1 - mn) * cost1 + (need2 - mn) * cost2

        c3 = max(need1, need2) * costBoth

        return min(c1, c2, c3)