class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] req = new int[26];

        for (char ch : licensePlate.toLowerCase().toCharArray()) {
            if (ch >= 'a' && ch <= 'z') {
                req[ch - 'a']++;
            }
        }

        String ans = "";

        for (String wrd : words) {
            int[] cnt = new int[26];

            for (char ch : wrd.toCharArray()) {
                cnt[ch - 'a']++;
            }

            boolean ok = true;

            for (int i = 0; i < 26; i++) {
                if (cnt[i] < req[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok && (ans.isEmpty() || wrd.length() < ans.length())) {
                ans = wrd;
            }
        }

        return ans;
    }
}