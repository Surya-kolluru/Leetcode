#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        while (j < len && strs[i][j] == strs[0][j]) {
            j++;
        }

        len = j;

        if (len == 0) {
            return "";
        }
    }

    char* ans = malloc(len + 1);
    strncpy(ans, strs[0], len);
    ans[len] = '\0';

    return ans;
}