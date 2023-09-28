class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> X(query_row + 1, vector<double>(query_row + 10));

        X[0][0] = poured;
        for (int i = 0; i < query_row; i++){
            for (int j = 0; j <= i; j++){
                if (X[i][j] <= 1) continue;

                X[i][j] -= 1;
                X[i + 1][j] += X[i][j] / 2;
                X[i + 1][j + 1] += X[i][j] / 2;
            }
        }

        return (min(1.0, X[query_row][query_glass]));
    }
};
