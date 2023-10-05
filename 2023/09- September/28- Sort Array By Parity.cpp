class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        vector<int> X(nums.size());

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] % 2) X[r--] = nums[i];
            else X[l++] = nums[i];
        }

        return (X);
    }
};
