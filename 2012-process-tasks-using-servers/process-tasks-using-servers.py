import heapq
from typing import List

class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        free = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(free)

        busy = []
        ans = []
        time = 0

        for i, task in enumerate(tasks):
            time = max(time, i)

            while busy and busy[0][0] <= time:
                t, w, idx = heapq.heappop(busy)
                heapq.heappush(free, (w, idx))

            if not free:
                time = busy[0][0]

                while busy and busy[0][0] <= time:
                    t, w, idx = heapq.heappop(busy)
                    heapq.heappush(free, (w, idx))

            w, idx = heapq.heappop(free)
            ans.append(idx)

            heapq.heappush(busy, (time + task, w, idx))

        return ans