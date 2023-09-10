class Solution {
public:
    bool searchMatrix(vector<vector<int>>& X, int target) {
        for (auto i : X)
            for (auto j : i)
                if (j== target)
                    return (1);
                    
        return (0);
    }
};