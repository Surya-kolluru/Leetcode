class Solution {
    public void moveZeroes(int[] nums) {
        int pos = 0;

        for (int val : nums) {
            if (val != 0) {
                nums[pos++] = val;
            }
        }

        while (pos < nums.length) {
            nums[pos++] = 0;
        }
    }
}