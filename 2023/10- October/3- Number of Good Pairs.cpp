class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int summ = 0;

        vector<int> Z(101);

        for (int i = 0; i < nums.size(); i++)
            summ += Z[nums[i]]++;

        return (summ);
    }
};