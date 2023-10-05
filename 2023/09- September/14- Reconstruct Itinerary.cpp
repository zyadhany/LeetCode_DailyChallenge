class Solution {
public:
    vector<string> sol;
    unordered_map<string, multiset<string>> edge;

    void dfs(string s){
        string t;

        while (!edge[s].empty()){
            t = *edge[s].begin();
            edge[s].erase(edge[s].begin());
            dfs(t);
        }

        sol.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &m : tickets)
            edge[m[0]].insert(m[1]);
        
        dfs("JFK");
        reverse(sol.begin(), sol.end());
        return (sol);
    }
};
