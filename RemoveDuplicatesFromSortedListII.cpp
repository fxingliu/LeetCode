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
        if (!head) return NULL;
        if (head->next && head->next->val == head->val) {
            while (head->next && head->next->val == head->val) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
            }
            ListNode* newHead = head->next;
            delete head;
            return deleteDuplicates(newHead);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
