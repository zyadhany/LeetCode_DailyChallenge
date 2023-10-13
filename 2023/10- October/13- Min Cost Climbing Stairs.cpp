class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> Z(n + 2,INT32_MAX);
        Z[0] = Z[1] = 0;

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= 2; j++)
                Z[i + j] = min(Z[i + j], Z[i] + cost[i]);
            
        return Z[n];
    }
};
