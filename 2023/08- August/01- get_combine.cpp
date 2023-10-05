class Solution {
public:
    vector<int> Temp;
    vector<vector<int>> sol;

    vector<vector<int>> combine(int n, int k) {
        Temp.resize(k);

        get_combine(n, k);
        return sol;
    }

    void get_combine(int n, int k){
        if (!k){
            sol.push_back(Temp);
            return;
        }

        for (int i = n; i > 0 && i >= k; i--){
            Temp[k - 1] = i;
            get_combine(i - 1, k - 1);
        }
    }
};
