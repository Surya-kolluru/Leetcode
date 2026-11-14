class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        java.util.HashMap<Integer, Integer> mp = new java.util.HashMap<>();
        java.util.ArrayList<Integer> ans = new java.util.ArrayList<>();

        for (int x : nums1) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        for (int x : nums2) {
            if (mp.getOrDefault(x, 0) > 0) {
                ans.add(x);
                mp.put(x, mp.get(x) - 1);
            }
        }

        int[] res = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}