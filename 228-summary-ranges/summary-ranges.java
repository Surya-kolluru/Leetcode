class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        int n = nums.length;
        int i = 0;

        while (i < n) {
            int st = nums[i];

            while (i + 1 < n && (long) nums[i + 1] == (long) nums[i] + 1) {
                i++;
            }

            int en = nums[i];

            if (st == en) {
                ans.add(String.valueOf(st));
            } else {
                ans.add(st + "->" + en);
            }

            i++;
        }

        return ans;
    }
}