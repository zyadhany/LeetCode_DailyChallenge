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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = 1;
        ListNode *tmp = head;

        vector<ListNode *> X(right - left + 1);

        while (n <= right)
        {
            if (n >= left)
                X[n - left] = tmp;
            
            tmp = tmp->next;
            n++;
        }

        for (int i = 0; i < X.size() / 2; i++)
            swap(X[i]->val, X[X.size() - i - 1]->val);

        return head;
    }
};
