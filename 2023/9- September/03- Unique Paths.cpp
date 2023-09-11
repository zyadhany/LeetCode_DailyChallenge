class Solution {
public:
    map<pair<int,int>,int> X;

    int uniquePaths(int n, int m) {
        if(n==0 || m == 0) return 0;
        if(n==1 || m == 1) return 1;
        if(X.count({n,m})) return X[{n,m}];
        X[{n,m}] = uniquePaths(n-1,m) + uniquePaths(n,m-1);
        X[{m,n}] = X[{n,m}];
        return X[{n,m}];
    }
};