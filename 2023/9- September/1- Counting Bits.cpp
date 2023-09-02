class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> X(n + 1);
        int k, cnt;

        for (int i = 0; i <= n; i++) {
            k = i, cnt = 0;

            while (k) {
                cnt += k % 2;
                k /= 2;
            }

            X[i] = cnt;
        }

        return X;
    }
};