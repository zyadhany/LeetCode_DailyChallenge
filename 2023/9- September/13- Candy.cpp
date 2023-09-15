class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), summ = 0, re;

        vector<int> Z(n, 1);
        vector<pair<int, int>> X(n);

        for (int i = 0; i < n; i++)
            X[i].first = ratings[i], X[i].second = i;

        sort(X.begin(), X.end());
        ratings.push_back(INT32_MAX);

        for(int i = 0; i < X.size(); i++){
            re = X[i].second;

            if (ratings[re] > ratings[re + 1])
                Z[re] = max(Z[re], Z[re + 1] + 1);

            if (re)
                if (ratings[re] > ratings[re - 1])
                    Z[re] = max(Z[re], Z[re - 1] + 1);
            
            summ += Z[re];
        }

        return (summ);
    }
};
