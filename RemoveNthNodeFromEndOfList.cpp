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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        getNFromEnd(&dummy, n);
        return dummy.next;
    }
    
private:
    int getNFromEnd(ListNode* p, int n) {
        if (!p) return -1;
        int ret = getNFromEnd(p->next, n)+1;
        if (ret == n) {
            ListNode *tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
        return ret;
    }
};
