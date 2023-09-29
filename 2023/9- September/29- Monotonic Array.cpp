class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), i;

        for (i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i-1]) break;
        if (i == n) return (1);

        for (i = 1; i < nums.size(); i++)
            if (nums[i] > nums[i-1]) break;
        if (i == n) return (1);

        return (0);
    }
};
