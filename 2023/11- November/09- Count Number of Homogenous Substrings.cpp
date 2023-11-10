const int MODE = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
       long long ans = 0, re = 1;

        s += "#";
        for (int i = 1; i < s.size(); i++){
            if (s[i] != s[i - 1]){
                ans += re * (re + 1) / 2;
                re = 0;
            }
            re++;
        }

       return (ans % MODE); 
    }
};