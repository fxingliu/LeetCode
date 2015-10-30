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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2, dummy(0);
        ListNode *t = &dummy;
        while (p && q) {
            if (p->val < q->val) {
                t->next = p;
                p = p->next;
            }
            else {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        t->next = (p) ? p : q;
        return dummy.next;
    }
};
