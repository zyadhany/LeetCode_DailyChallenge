/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0, m;

        ListNode *tmp = head, *Y;
        vector<ListNode*> X(k);

        while (tmp)
            n++, tmp = tmp->next;
        
        tmp = head;
        for (int i = 0; i < k; i++){
            m = n / k + (i < n % k);
            if (!m) continue;

            X[i] = new ListNode(tmp->val);
            tmp = tmp->next;

            Y = X[i];
            for (int j = 1; j < m; j++){
                Y->next = new ListNode(tmp->val);
                Y = Y->next;
                tmp = tmp->next;
            }
        }

        return X;
    }
};
