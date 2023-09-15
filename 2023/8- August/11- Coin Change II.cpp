const int MODE = INT32_MAX;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> Z(amount + 1);

        Z[0] = 1;

        for (int i = 0; i < coins.size(); i++){
            for (int j = 0; j < amount; j++){
                if (j + coins[i] > amount) break;
                Z[j + coins[i]] += Z[j] % MODE;
            }
        }

        return (Z[amount]);
    }
};
