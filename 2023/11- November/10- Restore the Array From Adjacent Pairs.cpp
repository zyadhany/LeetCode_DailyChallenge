class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size(), at = 0;

        vector<int> Z(n + 1);        
        map<int, vector<int>> Y;

        for (auto &m : adjacentPairs){
            Y[m[0]].push_back(m[1]);
            Y[m[1]].push_back(m[0]);
        }

        for (auto &m : Y)
            if (m.second.size() == 1){
                at = m.first;
                break;
            }

        Z[0] = at;
        at = Y[at][0];
        Y[Z[0]].clear();

        for (int i = 1; i <= n; i++){
            Z[i] = at;

            for (auto &a : Y[at])
                if (Y[a].size())
                    at = a;

            Y[Z[i]].clear();
        }

        return (Z);
    }
};