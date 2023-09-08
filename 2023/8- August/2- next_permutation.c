class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        
        do{
            sol.push_back(nums);
        }while (next_permutation(nums.begin(), nums.end()));


        return sol;
    }
};