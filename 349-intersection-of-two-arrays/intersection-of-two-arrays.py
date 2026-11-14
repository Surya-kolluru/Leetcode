class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        st = set(nums1)
        ans = []

        for x in nums2:
            if x in st:
                ans.append(x)
                st.remove(x)

        return ans