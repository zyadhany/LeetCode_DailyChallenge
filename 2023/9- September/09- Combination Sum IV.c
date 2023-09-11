class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> X(target + 1);
        X[0] = 1;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < target; i++){
            if (!X[i]) continue;
            for (int j = 0; j < nums.size(); j++){
                if(i + nums[j] > target) break;

                X[i + nums[j]] += X[i];
                X[i + nums[j]] %= INT32_MAX;
            }
        }

        return (X[target]);
    }
};
