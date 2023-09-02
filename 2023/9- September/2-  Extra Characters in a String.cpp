class Solution {
public:

    int minExtraChar(string s, vector<string>& Dic) {
        int mx = 0;

        vector<int> Z(s.size() + 10, 0);
        sort(Dic.begin(), Dic.end());

        for (int i = s.size() - 1; i >= 0; i--)
        {
            string t;
            Z[i] = Z[i + 1];

            for (int j = i; j < s.size(); j++) {
                t += s[j];
                if (binary_search(Dic.begin(), Dic.end(), t))
                    Z[i] = max(Z[i], Z[j + 1] + j - i + 1);
            }

            mx = max(mx, Z[i]);
        }

        return s.size() - mx;
    }
};