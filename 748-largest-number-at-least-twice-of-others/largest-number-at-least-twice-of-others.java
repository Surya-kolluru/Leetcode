class Solution {
    public int dominantIndex(int[] nums) {
        int mx = -1, idx = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                idx = i;
            }
        }

        for (int x : nums) {
            if (x != mx && mx < 2 * x) {
                return -1;
            }
        }

        return idx;
    }
}