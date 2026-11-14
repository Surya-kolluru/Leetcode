class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        cnt = {}
        ans = []

        for x in nums1:
            cnt[x] = cnt.get(x, 0) + 1

        for x in nums2:
            if cnt.get(x, 0) > 0:
                ans.append(x)
                cnt[x] -= 1

        return ans