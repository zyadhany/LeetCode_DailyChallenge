/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		int mx = INT32_MIN;

		vector<int> sol;
		queue<TreeNode*> Q, Z;

		if (root)
			Q.push(root);

		while (!Q.empty()) 
		{
            while (!Q.empty()){
                TreeNode node = *Q.front();
                Q.pop();

                mx = max(mx, node.val);

                if (node.left) Z.push(node.left);
                if (node.right) Z.push(node.right);
            }

            sol.push_back(mx);
			mx = INT32_MIN;
			swap(Q, Z);
		}

		return (sol);
	}
};
