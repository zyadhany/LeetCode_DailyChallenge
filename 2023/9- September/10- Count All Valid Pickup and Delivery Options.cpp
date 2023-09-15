class Solution {
public:
    int countOrders(int n) {
        long long summ = 1;
        const int MODE = 1e9 + 7;

        for (int i = 1; i <= n; i++)
            summ = (summ * i * (2 * i - 1)) % MODE;

        return (summ);
    }
};
