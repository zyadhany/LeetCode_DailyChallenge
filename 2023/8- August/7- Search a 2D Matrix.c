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


/*solve using upper and lower pound*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] > target) return (0);

        int l, r;
        vector<int> Y = { target, INT32_MAX };

        l = upper_bound(matrix.begin(), matrix.end(), Y) - matrix.begin() - 1;
        r = lower_bound(matrix[l].begin(), matrix[l].end(), target) - matrix[l].begin();

        if (r >= matrix[0].size()) return(0);

        return (matrix[l][r] == target);
    }
};