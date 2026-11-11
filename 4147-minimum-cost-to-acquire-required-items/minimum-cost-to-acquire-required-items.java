class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long c1 = (long) need1 * cost1 + (long) need2 * cost2;

        int mn = Math.min(need1, need2);
        long c2 = (long) mn * costBoth
                + (long) (need1 - mn) * cost1
                + (long) (need2 - mn) * cost2;

        long c3 = (long) Math.max(need1, need2) * costBoth;

        return Math.min(c1, Math.min(c2, c3));
    }
}