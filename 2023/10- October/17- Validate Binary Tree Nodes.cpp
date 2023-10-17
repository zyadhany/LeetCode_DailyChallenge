class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int nodes = 0, start, re;

        vector<int> vis(n), freq(n + 1);
        queue<int> q;

        for (int i = 0; i < n; i++)
            freq[leftChild[i] + 1]++, freq[rightChild[i] + 1]++;
        for (int i = 1; i <= n; i++)
            if (!freq[i]){start = i - 1; break;}

        q.push(start);

        while (!q.empty()){
            re = q.front();
            q.pop();
            
            if (re == -1) continue;
            if (vis[re]) return (0);
            
            vis[re] = 1;
            nodes++;
            
            q.push(leftChild[re]);
            q.push(rightChild[re]);
        }

        return (nodes == n);
    }
};
