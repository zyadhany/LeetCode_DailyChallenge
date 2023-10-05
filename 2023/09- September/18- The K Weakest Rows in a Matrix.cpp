class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n, m;

        n = mat.size();
        m = mat[0].size();

        vector<int> Z(k);
        vector<pair<vector<int>, int>> X(n);

        for (int i = 0; i < n; i++)
            X[i] = {mat[i], i};

        sort(X.begin(), X.end());

        for (int i = 0; i < k; i++)
            Z[i] = X[i].second;

        return (Z);
    }
};
