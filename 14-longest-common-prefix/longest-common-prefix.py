class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pre = strs[0]

        for st in strs[1:]:
            while not st.startswith(pre):
                pre = pre[:-1]
                if not pre:
                    return ""

        return pre