class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), re, prev;

        vector<int> Z(m + 1, -1e9);

        for (int i = 0; i < n; i++){
            prev = Z[0];
            for (int j = 0; j < m; j++){
                re = max(prev, max(prev, 0) + nums1[i] * nums2[j]);
                prev = Z[j + 1];
                Z[j + 1] = max(Z[j + 1], re);
                Z[j + 1] = max(Z[j + 1], Z[j]);
            }
        }

        return (Z[m]);
    }
};