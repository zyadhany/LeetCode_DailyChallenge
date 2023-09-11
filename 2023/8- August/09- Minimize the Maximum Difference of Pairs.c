class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0, r = 1e9, at, re;
        sort(nums.begin(), nums.end());

        while (l < r){
            at = l + (r - l) / 2;
            re = 0;

            for (int i = 0; i < nums.size() - 1; i++){
                if (nums[i + 1] - nums[i] <= at){
                    re++;
                    i++;
                }
            }

            if (re >= p){
                r = at;
            }else l = at + 1;
        }

        return (l);
    }
};
