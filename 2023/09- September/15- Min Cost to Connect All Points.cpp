class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int summ = 0, mn, re;
        pair<int,int> k;

        set<pair<int, int>> L , R;

        L.insert({points[0][0], points[0][1]});
        for (int i = 1; i < points.size(); i++)
            R.insert({points[i][0], points[i][1]});

        while (!R.empty()){
            mn = INT32_MAX;

            for (auto &l : L)
                for (auto &r : R){
                    re = abs(l.first - r.first) + abs(l.second - r.second);
                    if (re < mn)
                        k = r, mn = re;
                }

            summ += mn;
            L.insert(k);
            R.erase(k);
        }

        return summ;
    }
};
