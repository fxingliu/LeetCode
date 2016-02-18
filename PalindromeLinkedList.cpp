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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        ListNode* following = slow;
        if (fast) slow = slow->next;
        // the first half is reversed and leading by prev
        // we can actually restore the first half while checking palindrome
        while (slow) {
            if (slow->val != prev->val) return false;
            slow = slow->next;
            ListNode *tmp = prev->next;
            prev->next = following;
            following = prev;
            prev = tmp;
        }
        return true;
    }
};
