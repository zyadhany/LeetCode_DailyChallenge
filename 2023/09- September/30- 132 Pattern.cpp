class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mn = INT32_MAX;

        multiset<int> X;

        for (auto &m : nums)
            X.insert(m);

        for (auto &m : nums){
            auto it = X.find(m);

            if (it != X.begin()){
                it--;
                if (mn < *it) return (1);
                it++;
            }

            mn = min(mn, m);
            X.erase(it);
        }

        return (0);
    }
};
