class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        vector<vector<long long>> X(n + 1, vector<long long>(m + 1));
        X[n][m-1] = 1;

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                if (!obstacleGrid[i][j])
                    X[i][j] = X[i + 1][j] + X[i][j + 1];

        return (X[0][0]);
    }
};
