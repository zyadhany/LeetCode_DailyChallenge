class Solution {
public:
    vector<bool> vis;

    bool wordBreak(string s, vector<string>& wordDict) {
        vis.resize(s.size() + 1, 0);
        return sprate_word(wordDict, s, 0);
    }

    bool sprate_word(vector<string> &wordDict, string &s, int n){
        if (n == s.size()) return(1);
        if (vis[n]) return (0);
        string t;

        for (int i = n; i < s.size(); i++){
            t += s[i];
            for (int j = 0; j < wordDict.size(); j++)
                if (t == wordDict[j])
                    if(sprate_word(wordDict, s, i + 1)) return (1);
        }

        vis[n] = 1;
        return (0);
    }
};
