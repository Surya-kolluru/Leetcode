class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        ans = float('inf')

        for i in range(n):
            sm = 0
            for j in range(i, min(n, i + r)):
                sm += nums[j]
                ln = j - i + 1

                if ln >= l and sm > 0:
                    ans = min(ans, sm)

        return ans if ans != float('inf') else -1