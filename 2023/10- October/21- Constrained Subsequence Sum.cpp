class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> Z(n);
        multiset<int> Y;

        Y.insert(nums.back());
        Z[n - 1] = nums.back();
        for (int i = n - 2; i >= 0; i--){
            Z[i] = nums[i];

            auto it = Y.end();
            it--;

            Z[i] += max(*it, 0);
            if (Y.size() == k) Y.erase(Y.find(Z[i + k]));
            Y.insert(Z[i]);
        }

        return (*max_element(Z.begin(), Z.end()));
    }
};
