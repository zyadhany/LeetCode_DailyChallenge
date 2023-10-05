class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), mn = INT32_MAX, re, k;

        vector<int> L(n + 1), R(n + 1);

        for (int i = 1; i <= n; i++){
            L[i] = nums[i - 1] + L[i - 1];
            R[i] = nums[n - i] + R[i - 1];
        }

        for (int i = 0; i <= n && x >= L[i]; i++){
            k = x - L[i];
            re = upper_bound(R.begin(), R.end(), k) - R.begin() - 1;
            if (R[re] == k && re + i <= n) mn = min(mn, re + i);
        }

        if (mn == INT32_MAX) return (-1);
        return (mn);
    }
};
