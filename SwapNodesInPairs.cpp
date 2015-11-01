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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur->next->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        return dummy.next;
    }
};
