class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        can = 0
        cnt = 0

        for num in nums:
            if cnt == 0:
                can = num

            if num == can:
                cnt += 1
            else:
                cnt -= 1

        return can