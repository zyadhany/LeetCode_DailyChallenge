const int MODE = 1e9 + 7;

class Solution {
public:
    vector<vector<long long>> Z;
    vector<long long> fac;
    
    int numMusicPlaylists(int n, int goal, int k) {
        long long summ = 1;

        Z.resize(n + 1, vector<long long>(goal + 1));
        fac.resize(n + 1);

        fac[0] = 1;
        for (int i = 1; i < fac.size(); i++)
                fac[i] = (i * fac[i - 1]) % MODE;

        for (int i = 0; i <= k; i++)
            summ = (summ * (n - i)) % MODE;

        summ *= req(n - k - 1, n - k , goal - k - 1);
        
        return (summ % MODE);
    }

    long long req(int n, int k, int len){
        if (n > len || n < 0) return (0);
        if (Z[n][len]) return Z[n][len];
        if (len == n) return fac[n];

        Z[n][len] = (k - n) * req(n , k, len - 1);
        Z[n][len] += n * req(n - 1, k, len - 1);
        Z[n][len] %= MODE;

        return (Z[n][len] % MODE);
    }
};
