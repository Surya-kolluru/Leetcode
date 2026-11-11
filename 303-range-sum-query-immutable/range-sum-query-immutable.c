typedef struct {
    int* pre;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->pre = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        obj->pre[i + 1] = obj->pre[i] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->pre[right + 1] - obj->pre[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->pre);
    free(obj);
}