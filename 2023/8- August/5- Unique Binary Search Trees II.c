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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> X(n);
        vector<TreeNode *> Z;

        for (int i = 1; i <= n; i++)
            X[i - 1] = i;

        do{
            TreeNode* tmp = creat_tree(X);
            if (!is_here(Z, tmp))
                Z.push_back(tmp);
        }while(next_permutation(X.begin(), X.end()));

        return Z;
    }

    TreeNode *creat_tree(vector<int> X){
        TreeNode* tmp = new TreeNode(X.front());
        for (int i = 1; i < X.size(); i++)
            add_node(tmp, X[i]);
        return tmp;
    }

    void add_node(TreeNode *node, int n){
        if (n >= node->val){
            if (node->right)
                add_node(node->right, n);
            else node->right = new TreeNode(n);
        }else{
            if (node->left)
                add_node(node->left, n);
            else node->left = new TreeNode(n);
        }
    }

    bool is_here(vector<TreeNode *> Z, TreeNode *node){
        for (int i = 0; i < Z.size(); i++)
            if (check_nodes(Z[i], node))
                return (1);

        return (0);
    }

    bool check_nodes(TreeNode *node1, TreeNode *node2){
        if (!node1 && !node2) return (1);
        if ((!node1 && node2) || (node1 && !node2)) return (0);
        if (node1->val != node2->val) return (0);
        return (check_nodes(node1->left, node2->left) * check_nodes(node1->right, node2->right));
    }

};
