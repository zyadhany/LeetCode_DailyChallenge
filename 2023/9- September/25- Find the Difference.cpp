class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> X(255), Y(255);

        for (int i = 0; i < s.size(); i++)
            X[s[i]]++, Y[t[i]]++;
        Y[t.back()]++;

        for (int i = 'a'; i <= 'z'; i++)
            if (X[i] != Y[i]) return (i);
        return ('a');
    }
};
