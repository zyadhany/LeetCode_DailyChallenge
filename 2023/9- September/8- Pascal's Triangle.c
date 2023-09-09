class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> X;

        for (int i = 1; i <= n; i++){
            X.push_back(vector<int>(i, 1));
            for (int j = 1; j < i - 1; j++)
                X[i-1][j] = X[i-2][j-1] + X[i-2][j];
        }

        return (X);
    }
};
