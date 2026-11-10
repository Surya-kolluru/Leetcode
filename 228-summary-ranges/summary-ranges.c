char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** ans = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;

    int i = 0;

    while (i < numsSize) {
        int st = nums[i];

        while (i + 1 < numsSize && (long long)nums[i + 1] == (long long)nums[i] + 1) {
            i++;
        }

        int en = nums[i];
        ans[*returnSize] = (char*)malloc(32 * sizeof(char));

        if (st == en) {
            sprintf(ans[*returnSize], "%d", st);
        } else {
            sprintf(ans[*returnSize], "%d->%d", st, en);
        }

        (*returnSize)++;
        i++;
    }

    return ans;
}