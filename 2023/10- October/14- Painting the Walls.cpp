class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size(), mn = INT32_MAX, re;

        vector<int> Z(n * 2 + 1, INT32_MAX);

        Z[n] = 0;
        for (int i = 0; i < n; i++){
            vector<int> Y(2 * n + 1, INT32_MAX);

            for (int j = 0; j < Z.size(); j++){
                if (Z[j] == INT32_MAX) continue;
                re = min(j + time[i], 2 * n);
                Y[j - 1] = min(Y[j - 1], Z[j]);
                Y[re] = min(Y[re], Z[j] + cost[i]);
            }

            Z = Y;
        }

        for (int i = n; i < Z.size(); i++)
            mn = min(mn, Z[i]);

        return (mn);
    }
};
