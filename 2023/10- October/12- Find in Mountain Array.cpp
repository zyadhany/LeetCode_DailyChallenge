/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n, m, l , r, at, a, b , c;

        n = mountainArr.length();

        l = 1, r = n - 2;
        while (l <= r){
            m = (l + r) / 2;

            a = mountainArr.get(m - 1);
            b = mountainArr.get(m);
            c = mountainArr.get(m + 1);

            if (a < b && b < c) l = m + 1;
            else if (a > b && b > c) r = m - 1;
            else break;
        }

        l = 0, r = m;
        while (l <= r){
            at = (l + r) / 2;

            a = mountainArr.get(at);

            if (a < target) l = at + 1;
            else if (a > target) r = at - 1;
            else return (at);
        }

        l = m, r = n - 1;
        while (l <= r){
            at = (l + r) / 2;

            a = mountainArr.get(at);

            if (a > target) l = at + 1;
            else if (a < target) r = at - 1;
            else return (at);
        }

        return (-1);
    }
};
