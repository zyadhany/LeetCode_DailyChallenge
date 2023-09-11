class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l , r, at, re;

        l = 0, r = n - 1;
        if (nums[l] > nums[r])
            while (l < r){
                at = (l + r) / 2;

                if (nums[at] < nums[0])
                    r = at;
                else l = at + 1;
            }
        re = l;

        l = 0, r = n - 1;
        while (l <= r){
            at = (l + r) / 2;

            if (nums[(at + re) % n] == target)
                return ((at + re) % n);
            else if (nums[(at + re) % n] > target)
                r = at - 1;
            else l = at + 1;
        }

        return (-1);
    }
};
