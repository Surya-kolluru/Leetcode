class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        req = [0] * 26

        for ch in licensePlate.lower():
            if ch.isalpha():
                req[ord(ch) - 97] += 1

        ans = ""

        for wrd in words:
            cnt = [0] * 26

            for ch in wrd:
                cnt[ord(ch) - 97] += 1

            if all(cnt[i] >= req[i] for i in range(26)):
                if not ans or len(wrd) < len(ans):
                    ans = wrd

        return ans