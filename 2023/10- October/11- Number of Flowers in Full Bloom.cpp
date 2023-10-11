class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size(), summ = 0;

        vector<int> sol(n);
        map<vector<int>, int> X;

        for (int i = 0; i < flowers.size(); i++){
            X[{flowers[i][0], 0, 1}]++;
            X[{flowers[i][1] + 1, 0, -1}]++;
        }

        for (int i = 0; i < n; i++)
            X[{people[i], 1, i}];

        for (auto m : X)
            if (m.first[1]) sol[m.first[2]] = summ;
            else summ += m.first[2] * m.second;

        return (sol);
    }
};
