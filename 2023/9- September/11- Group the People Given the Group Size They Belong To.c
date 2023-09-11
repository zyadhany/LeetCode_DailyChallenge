class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> X(groupSizes.size() + 1), Z;

        for (int i = 0; i < groupSizes.size(); i++){
            X[groupSizes[i]].push_back(i);
            if (X[groupSizes[i]].size() == groupSizes[i]){
                Z.push_back(X[groupSizes[i]]);
                X[groupSizes[i]].clear();
            }
        }

        return (Z);
    }
};
