class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return (1);
        if (n % 4 || n <= 0) return (0);
        return isPowerOfFour(n / 4);
    }
};
