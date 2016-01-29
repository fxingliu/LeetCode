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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *q = head;
        while (q) {
            while (q->next && q->next->val == q->val) 
                q = q->next;
            if (p->next == q) {
                p = q;
                q = q->next;
            }
            else {
                ListNode *tmp = p->next;
                p->next = q->next;
                // release memory
                while (tmp != p->next) {
                    q = tmp->next;
                    delete tmp;
                    tmp = q;
                }
                q = tmp;
            }
        }
        return dummy.next;
    }
};
