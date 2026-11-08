#include <stdlib.h>

int countServers(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int* row = calloc(m, sizeof(int));
    int* col = calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                ans++;
            }
        }
    }

    free(row);
    free(col);

    return ans;
}