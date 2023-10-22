class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0, l, r;

        vector<pair<int, int>> X(n);

        for (int i = 0; i < n; i++)
            X[i] = {nums[i], i};
        sort(X.begin(), X.end());

        l = 0, r = n - 1;
        for (int i = 0; i < n; i++){
            if (X[i].second < l || X[i].second > r)  continue;

            mx = max(mx, X[i].first * (r - l + 1));

            if (X[i].second <= k) l = X[i].second + 1;
            if (X[i].second >= k) r = X[i].second - 1;
        }

        return (mx);
    }
};
