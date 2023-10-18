class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int mx = 0;

        vector<int> Z(n + 1);
        vector<vector<int>> Y(n + 1);

        for (int i = 0; i < relations.size(); i++)
            Y[relations[i][1]].push_back(relations[i][0]);

        for (int i = 1; i <= n; i++)
            mx = max(mx, req(Y, Z, time, i));

        return (mx);
    }

    int req(vector<vector<int>> &Y, vector<int> &Z, vector<int>& time, int n){
        if (Z[n]) return (Z[n]);
        int mx = 0;

        for (int i = 0; i < Y[n].size(); i++)
            mx = max(mx, req(Y, Z, time, Y[n][i]));

        return (Z[n] = time[n - 1] + mx);
    }
};
