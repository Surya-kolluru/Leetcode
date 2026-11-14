class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        java.util.HashSet<Integer> st = new java.util.HashSet<>();
        java.util.ArrayList<Integer> ans = new java.util.ArrayList<>();

        for (int x : nums1) {
            st.add(x);
        }

        for (int x : nums2) {
            if (st.contains(x)) {
                ans.add(x);
                st.remove(x);
            }
        }

        int[] res = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}