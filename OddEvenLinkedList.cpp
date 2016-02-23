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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *odd = head, *even = head->next, *cur = head->next->next;
        ListNode *evenHead = even;
        int count = 2;
        while (cur) {
            if (++count % 2) {
                odd->next = cur;
                odd = cur;
            } 
            else {
                even->next = cur;
                even = cur;
            }
            cur = cur->next;
        }
        even->next = NULL;
        odd->next = evenHead;
        return head;
    }
};
