class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l, r;
        vector<int> res;

        l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if (l > r || r < 0 || nums[max(r, 0)] != target) res = {-1, -1};
        else res = {l, r};;

        return (res);
    }
};
