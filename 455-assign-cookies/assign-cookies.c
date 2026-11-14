#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0, j = 0, ans = 0;

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            ans++;
            i++;
        }
        j++;
    }

    return ans;
}