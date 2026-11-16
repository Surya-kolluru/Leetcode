#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* digitSum(char* s, int k) {
    int n = strlen(s);
    char* cur = malloc(105);
    strcpy(cur, s);

    while (n > k) {
        char* res = malloc(105);
        int idx = 0;

        for (int i = 0; i < n; i += k) {
            int sum = 0;

            for (int j = i; j < i + k && j < n; j++) {
                sum += cur[j] - '0';
            }

            idx += sprintf(res + idx, "%d", sum);
        }

        res[idx] = '\0';
        free(cur);
        cur = res;
        n = idx;
    }

    return cur;
}