class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), mn = INT32_MAX, re;

        sort(nums.begin(), nums.end());

        vector<int> X(1, nums[0]);

        for (int i = 1; i < n; i++)
            if (nums[i] != nums[i -1]) X.push_back(nums[i]);

        for (int i = 0; i < X.size() ; i++){
            re = upper_bound(X.begin(), X.end(), X[i] + n - 1) - X.begin();
            mn = min(mn, n - re + i);
        }

        return (mn);
    }
};