import java.util.*;

class Solution {
    void upd(int[] bit, int idx, int val, int n) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int qry(int[] bit, int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    int kth(int[] bit, int n, int rank) {
        int idx = 0;
        int step = Integer.highestOneBit(n);

        while (step > 0) {
            int nxt = idx + step;

            if (nxt <= n && bit[nxt] < rank) {
                idx = nxt;
                rank -= bit[nxt];
            }

            step >>= 1;
        }

        return idx + 1;
    }

    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] bit = new int[k + 1];
        int[] cnt = new int[k];

        for (int i = 1; i <= k; i++) {
            bit[i] = i & -i;
        }

        PriorityQueue<long[]> busy = new PriorityQueue<>(
            (a, b) -> Long.compare(a[0], b[0])
        );

        for (int i = 0; i < arrival.length; i++) {
            long tim = arrival[i];

            while (!busy.isEmpty() && busy.peek()[0] <= tim) {
                long[] cur = busy.poll();
                upd(bit, (int) cur[1] + 1, 1, k);
            }

            int tot = qry(bit, k);

            if (tot == 0) continue;

            int sta = i % k;
            int suf = tot - qry(bit, sta);

            int srv;

            if (suf > 0) {
                srv = kth(bit, k, qry(bit, sta) + 1) - 1;
            } else {
                srv = kth(bit, k, 1) - 1;
            }

            upd(bit, srv + 1, -1, k);
            cnt[srv]++;

            busy.offer(new long[]{tim + load[i], srv});
        }

        int mx = 0;

        for (int x : cnt) {
            mx = Math.max(mx, x);
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.add(i);
            }
        }

        return ans;
    }
}