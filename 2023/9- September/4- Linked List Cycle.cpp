/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *cnt1, *cnt2;
        cnt1 = cnt2 = head;

        while (cnt1 && cnt1->next){
            cnt1 = cnt1->next->next;
            cnt2 = cnt2->next;
            
            if (cnt1 == cnt2)return (1);
        }

        return (0);
    }
};
