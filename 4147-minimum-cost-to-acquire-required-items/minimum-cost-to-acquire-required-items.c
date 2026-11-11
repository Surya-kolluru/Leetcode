long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long c1 = (long long)need1 * cost1 + (long long)need2 * cost2;

    int mn = need1 < need2 ? need1 : need2;
    long long c2 = (long long)mn * costBoth
                 + (long long)(need1 - mn) * cost1
                 + (long long)(need2 - mn) * cost2;

    int mx = need1 > need2 ? need1 : need2;
    long long c3 = (long long)mx * costBoth;

    long long ans = c1 < c2 ? c1 : c2;
    return ans < c3 ? ans : c3;
}