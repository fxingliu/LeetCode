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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        
        stack<ListNode*> _stack;
        while (head) {
            _stack.push(head);
            head = head->next;
        }
        
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!_stack.empty()) {
            tail->next = _stack.top();
            _stack.pop();
            tail = tail->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
