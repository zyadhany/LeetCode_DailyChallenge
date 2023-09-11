class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (auto a : nums)
            if (a == target)
                return (1);

        return (0);
    }
};
