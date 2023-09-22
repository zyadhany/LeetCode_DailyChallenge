class Solution {
public:
    bool isSubsequence(string s, string t) {
        int at = 0;

        for (auto &a : t){
            if (a == s[at]){
                at++;
                if (at == s.size()) break;
            }
        }

        return (at == s.size());
    }
};
