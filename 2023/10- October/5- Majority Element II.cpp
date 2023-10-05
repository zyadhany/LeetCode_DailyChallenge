class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        
        vector<int> sol;
        unordered_map<int, int> X;

        for (auto &m : nums)
            X[m]++;

        for (auto &m : X)
            if (m.second > n)
                sol.push_back(m.first);

        return (sol);
    }
};