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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *p=l1, *q=l2, *t=&dummy;
        int carry = 0;
        while (p || q) {
            int a = p ? p->val : 0;
            int b = q ? q->val : 0;
            int sum = a+b+carry;
            carry = sum/10;
            t->next = new ListNode(sum % 10);
            t = t->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry)
            t->next = new ListNode(1);
        return dummy.next;
    }
};
