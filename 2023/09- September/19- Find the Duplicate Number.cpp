class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int freq[100001] = {0};

        for (auto &m : nums){
            freq[m]++;
            if (freq[m] == 2) return (m);
        }

        return (0);
    }
};
