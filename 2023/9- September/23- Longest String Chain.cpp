// compare function to sort at string size
bool sort_with_size(string &s, string &t){
    return (s.size() < t.size());
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), mx = 1;

        vector<int> Z(n, 1);

        sort(words.begin(), words.end(), sort_with_size);

        // dp to get longest chain
        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++)
                if (is_predecessor(words[i], words[j]))
                    Z[i] = max(Z[i], 1 + Z[j]);
            mx = max(mx, Z[i]);
        }

        return (mx);
    }

    // check if 2 string are predecessor
    bool is_predecessor(string &s, string &t){
        int n = s.size(), m = t.size(), at = 0;

        if (n + 1 != m)
            return (0);

        for (int i = 0; i < m; i++)
            if (t[i] == s[at]) at++;
    
        return (at == n);
    }
};
