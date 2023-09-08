class Solution {
public:
    vector<string> sol;
    map<char,string> freq;

    vector<string> letterCombinations(string digits) {
        string s;
        freq['2'] = "abc";
        freq['3'] = "def";
        freq['4'] = "ghi";
        freq['5'] = "jkl";
        freq['6'] = "mno";
        freq['7'] = "pqrs";
        freq['8'] = "tuv";
        freq['9'] = "wxyz";

        if (!digits.empty())
            get_comb(s, digits);

        return sol;
    }

    void get_comb(string &s, string &digits){
        if (s.size() == digits.size()){
            sol.push_back(s);
            return;
        }

        for (auto m : freq[digits[s.size()]]){
            s += m;
            get_comb(s, digits);
            s.pop_back();
        }
    }
};
