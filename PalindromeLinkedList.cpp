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
        if (!head) return true;
        int len = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) len++;
        return helper(head, head, len, 0);
    }
    
private:
    bool helper(ListNode* head, ListNode*& mirror, int len, int step) {
        step++;
        if (step == (len+1)/2) {
            if (len%2) {
                mirror = head->next;
                return true;
            }
            else {
                mirror = head->next->next;
                return head->val == head->next->val;
            }
        }
        bool ret = helper(head->next, mirror, len, step) && head->val == mirror->val;
        mirror = mirror->next;
        return ret;
    }
};
