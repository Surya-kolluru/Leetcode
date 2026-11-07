#include <stdlib.h>

typedef struct {
    int wei, idx;
} Fre;

typedef struct {
    long long end;
    int wei, idx;
} Bus;

void pfr(Fre *hp, int *sz, Fre val) {
    int i = ++(*sz);

    while (i > 1 && (hp[i / 2].wei > val.wei ||
          (hp[i / 2].wei == val.wei && hp[i / 2].idx > val.idx))) {
        hp[i] = hp[i / 2];
        i /= 2;
    }

    hp[i] = val;
}

Fre ofr(Fre *hp, int *sz) {
    Fre res = hp[1];
    Fre val = hp[(*sz)--];

    int i = 1;

    while (i * 2 <= *sz) {
        int ch = i * 2;

        if (ch + 1 <= *sz &&
            (hp[ch + 1].wei < hp[ch].wei ||
            (hp[ch + 1].wei == hp[ch].wei &&
             hp[ch + 1].idx < hp[ch].idx))) {
            ch++;
        }

        if (val.wei < hp[ch].wei ||
            (val.wei == hp[ch].wei && val.idx < hp[ch].idx))
            break;

        hp[i] = hp[ch];
        i = ch;
    }

    if (*sz > 0) hp[i] = val;

    return res;
}

void pbs(Bus *hp, int *sz, Bus val) {
    int i = ++(*sz);

    while (i > 1 && hp[i / 2].end > val.end) {
        hp[i] = hp[i / 2];
        i /= 2;
    }

    hp[i] = val;
}

Bus obs(Bus *hp, int *sz) {
    Bus res = hp[1];
    Bus val = hp[(*sz)--];

    int i = 1;

    while (i * 2 <= *sz) {
        int ch = i * 2;

        if (ch + 1 <= *sz && hp[ch + 1].end < hp[ch].end)
            ch++;

        if (val.end <= hp[ch].end)
            break;

        hp[i] = hp[ch];
        i = ch;
    }

    if (*sz > 0) hp[i] = val;

    return res;
}

int* assignTasks(int* servers, int serversSize,
                 int* tasks, int tasksSize, int* returnSize) {

    Fre *fre = malloc((serversSize + 1) * sizeof(Fre));
    Bus *bus = malloc((serversSize + 1) * sizeof(Bus));
    int *ans = malloc(tasksSize * sizeof(int));

    int fsz = 0, bsz = 0;

    for (int i = 0; i < serversSize; i++) {
        Fre val = {servers[i], i};
        pfr(fre, &fsz, val);
    }

    long long tim = 0;

    for (int i = 0; i < tasksSize; i++) {
        if (tim < i) tim = i;

        while (bsz > 0 && bus[1].end <= tim) {
            Bus cur = obs(bus, &bsz);
            Fre val = {cur.wei, cur.idx};
            pfr(fre, &fsz, val);
        }

        if (fsz == 0) {
            tim = bus[1].end;

            while (bsz > 0 && bus[1].end <= tim) {
                Bus cur = obs(bus, &bsz);
                Fre val = {cur.wei, cur.idx};
                pfr(fre, &fsz, val);
            }
        }

        Fre srv = ofr(fre, &fsz);
        ans[i] = srv.idx;

        Bus val = {tim + tasks[i], srv.wei, srv.idx};
        pbs(bus, &bsz, val);
    }

    *returnSize = tasksSize;

    free(fre);
    free(bus);

    return ans;
}