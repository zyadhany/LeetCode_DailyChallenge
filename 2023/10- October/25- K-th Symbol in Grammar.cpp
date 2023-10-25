class Solution {
public:
    int kthGrammar(int n, int k) {
        int re = 0;

        k--;
        while (k){
            re += k % 2;
            k /= 2;
        }

        return (re % 2);
    }
};
