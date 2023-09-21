class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), size;
        int l = 0, r = 0, at = 0;

        size = n + m;

        vector<int> X(size);

        while (l < n && r < m)
            if (nums1[l] <= nums2[r]) X[at++] = nums1[l++];
            else X[at++] = nums2[r++];

        while (l < n)
            X[at++] = nums1[l++];

        while (r < m)
            X[at++] = nums2[r++];

        return (X[size / 2] + X[(size - 1) / 2]) / 2.0;
    }
};
