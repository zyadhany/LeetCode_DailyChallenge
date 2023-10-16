class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> X(rowIndex + 1, vector<int>(rowIndex + 1));

        for (int i = 0; i <= rowIndex; i++){
            X[i][0] = 1;
            for (int j = 1; j <= i; j++)
                X[i][j] = X[i - 1][j] + X[i - 1][j - 1];
        }

        return (X[rowIndex]);
    }
};
