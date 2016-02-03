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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = head, *start = &dummy, *prev = NULL;
        while (count < m) {
            start = cur;
            cur = cur->next;
            count++;
        }
        while (count <= n) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            count++;
        }
        start->next->next = cur;
        start->next = prev;
        return dummy.next;
    }
};
