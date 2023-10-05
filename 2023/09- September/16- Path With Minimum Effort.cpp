typedef pair<int, pair<int, int>> Pp;

vector<int> X = {1, -1, 0, 0},
            Y = {0, 0, 1, -1};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size(), l, r, k;
        pair<int, int> re;

        priority_queue<Pp, vector<Pp>, greater<Pp>> pq;
        pq.push({0, {n - 1, m - 1}});

        vector<vector<int>> Z(n, vector<int>(m, INT32_MAX));
        Z[n - 1][m - 1] = 0;

        while (!pq.empty()){
            re = pq.top().second;
            pq.pop();

            if(re == make_pair(0, 0))
                return (Z[0][0]);

            for (int i = 0; i < X.size(); i++){
                l = re.first + X[i], r = re.second + Y[i];
                if (l >= n || l < 0 || r >= m || r < 0)
                        continue;

                k = max(Z[re.first][re.second],
                        abs(heights[l][r] - heights[re.first][re.second]));

                if (Z[l][r] > k){
                    Z[l][r] = k;
                    pq.push({k, {l , r}});
                }
            }
        }

        return (Z[0][0]);   
    }
};
