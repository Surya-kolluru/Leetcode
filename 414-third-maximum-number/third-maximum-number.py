class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        a = b = c = None

        for x in nums:
            if x == a or x == b or x == c:
                continue

            if a is None or x > a:
                a, b, c = x, a, b
            elif b is None or x > b:
                b, c = x, b
            elif c is None or x > c:
                c = x

        return c if c is not None else a