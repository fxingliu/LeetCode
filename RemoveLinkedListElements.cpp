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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *q = head;
        while (q) {
            if (q->val != val) {
                p->next = q;
                p = q;
            }
            q = q->next;
        }
        p->next = q;
        return dummy.next;
    }
};
