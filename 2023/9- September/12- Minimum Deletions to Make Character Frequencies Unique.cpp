class Solution {
public:
    int minDeletions(string s) {
        long long summ = 0;

        vector<int> Z(255), X(s.size() + 1);
        
        for (int i = 0; i < s.size(); i++)
            Z[s[i]]++;

        for (int i = 'a'; i <= 'z'; i++)
            X[Z[i]]++;

        for (int i = s.size(); i >= 1; i--){
            if (!X[i]) continue;
            summ += X[i] - 1;
            X[i - 1] += X[i] - 1; 
        }

        return (summ);
    }
};
