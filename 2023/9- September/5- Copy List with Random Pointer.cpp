/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        
        unordered_map<Node*, Node*> X;
        X[NULL] = NULL;

        while (tmp)
            X[tmp] = new Node(tmp->val),
            tmp = tmp->next;

        tmp = head;
        while (tmp)
            X[tmp]->next = X[tmp->next],
            X[tmp]->random = X[tmp->random],
            tmp = tmp->next;

        return X[head];
    }
};
