import heapq
from typing import List

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        bit = [0] * (k + 1)

        for i in range(1, k + 1):
            bit[i] = i & -i

        def upd(idx, val):
            while idx <= k:
                bit[idx] += val
                idx += idx & -idx

        def qry(idx):
            res = 0
            while idx > 0:
                res += bit[idx]
                idx -= idx & -idx
            return res

        def kth(rank):
            idx = 0
            step = 1 << (k.bit_length() - 1)

            while step:
                nxt = idx + step
                if nxt <= k and bit[nxt] < rank:
                    idx = nxt
                    rank -= bit[nxt]
                step >>= 1

            return idx + 1

        busy = []
        cnt = [0] * k

        for i in range(len(arrival)):
            tim = arrival[i]

            while busy and busy[0][0] <= tim:
                end, srv = heapq.heappop(busy)
                upd(srv + 1, 1)

            tot = qry(k)

            if tot == 0:
                continue

            sta = i % k
            suf = tot - qry(sta)

            if suf > 0:
                srv = kth(qry(sta) + 1) - 1
            else:
                srv = kth(1) - 1

            upd(srv + 1, -1)
            cnt[srv] += 1

            heapq.heappush(busy, (tim + load[i], srv))

        mx = max(cnt)
        return [i for i in range(k) if cnt[i] == mx]