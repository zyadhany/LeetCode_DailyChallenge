// Time O(1), memory O(1)
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return (n - 1);

        int k = n / 3, r = n % 3;

        if (r == 1) return (pow(3, k - 1) * 4);
        return (pow(3, k) * pow(2, r / 2));
    }
};


// Dp solution -> Time O(nlog(n)), memory O(n)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> prime, Z(n + 1, 1);

        for (int i = 2; i < n; i++){
            for (int j = 0; j < prime.size(); j++)
                if (i % prime[j] == 0) goto EE;
            prime.push_back(i);
            EE:;
        }

        Z[0] = 1;

        for (int i = 0; i < n; i++){
            Z[i + 1] = max(Z[i + 1], Z[i]);
            for (int j = 0; j < prime.size(); j++){
                if (prime[j] + i > n) break;
                Z[prime[j] + i] = max(Z[prime[j] + i], Z[i] * prime[j]);
            }
        }

        return (Z[n]);
    }
};
