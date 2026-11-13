class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;
        int lg = 1;
        while ((1 << lg) <= n) lg++;

        int[] nxt = new int[n];
        int[] stk = new int[n];
        int top = 0;

        for (int i = n - 1; i >= 0; i--) {
            while (top > 0 && nums[stk[top - 1]] <= nums[i])
                top--;

            nxt[i] = top == 0 ? n : stk[top - 1];
            stk[top++] = i;
        }

        int[][] up = new int[lg][n];
        long[][] sm = new long[lg][n];

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            if (nxt[i] < n)
                sm[0][i] = (long) nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < lg; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];
                up[j][i] = mid == n ? n : up[j - 1][mid];

                sm[j][i] = sm[j - 1][i];
                if (mid < n)
                    sm[j][i] += sm[j - 1][mid];
            }
        }

        long[] pre = new long[n + 1];
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        long ans = 0;

        for (int r = 0; r < n; r++) {
            int lo = 0, hi = r;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                long mx = 0;
                int cur = mid;

                for (int j = lg - 1; j >= 0; j--) {
                    int end = up[j][cur];
                    if (end <= r) {
                        mx += sm[j][cur];
                        cur = end;
                    }
                }

                mx += (long) nums[cur] * (r - cur + 1);

                long cost = mx - (pre[r + 1] - pre[mid]);

                if (cost <= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans += r - lo + 1;
        }

        return ans;
    }
}