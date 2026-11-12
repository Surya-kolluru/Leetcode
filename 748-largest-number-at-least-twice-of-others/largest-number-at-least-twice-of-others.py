class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        mx = max(nums)
        idx = nums.index(mx)

        for x in nums:
            if x != mx and mx < 2 * x:
                return -1

        return idx