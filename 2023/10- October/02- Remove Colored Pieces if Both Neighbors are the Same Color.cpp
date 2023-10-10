class Solution {
public:
    bool winnerOfGame(string X) {
        map<char, int> Z;

        for (int i = 2; i < X.size(); i++)
            if (X[i] == X[i -1] && X[i] == X[i - 2])
                Z[X[i]]++;
        
        return Z['A'] > Z['B'];
    }
};