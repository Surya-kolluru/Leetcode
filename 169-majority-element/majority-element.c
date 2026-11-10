int majorityElement(int* nums, int numsSize) {
    int can = 0;
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (cnt == 0) {
            can = nums[i];
        }

        if (nums[i] == can) {
            cnt++;
        } else {
            cnt--;
        }
    }

    return can;
}