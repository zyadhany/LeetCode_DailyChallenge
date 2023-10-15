// dp solution
const int MODE = 1e9 + 7;

class Solution {
public:
    int ArrLen;
    map<pair<int, int>, long long> Z;

    int numWays(int steps, int arrLen) {
        vector<vector<int>> Z(steps + 1, vector<int>(steps + 1));

        Z[0][0] = 1;
        for (int i = 1; i <= steps; i++){
            for (int j = 0; j < arrLen; j++){
                if (j == i){
                    Z[i][j] = 1;
                    break;
                }
                Z[i][j] = Z[i - 1][j];
                Z[i][j] = (Z[i][j] + Z[i - 1][j + 1]) % MODE; 
                if (j) Z[i][j] = (Z[i][j] + Z[i - 1][j - 1]) % MODE; 
            }
        }

        return (Z[steps][0]);
    }
};

// recursion solution
const int MODE = 1e9 + 7;

class Solution {
public:
    int ArrLen;
    map<pair<int, int>, long long> Z;

    int numWays(int steps, int arrLen) {
        ArrLen = arrLen;
        return (req(0, steps));
    }

    long long req(int n, int k){
        if (n < 0 || n >= ArrLen || k < n) return (0);
        if (k == n) return (1);
        if (Z.count({n, k})) return (Z[{n, k}]);

        Z[{n, k}] = (req(n - 1, k - 1) + req(n + 1, k - 1) + req(n, k - 1)) % MODE;
        return (Z[{n, k}]);
    }
};