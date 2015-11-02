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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int end=lists.size()-1;
        while (end > 0) {
            int begin=0;
            while (begin < end)
                lists[begin] = merge2Lists(lists[begin++], lists[end--]);
        }
        return lists[0];
    }
    
private:
    ListNode* merge2Lists(ListNode *p, ListNode *q) {
        ListNode dummy(0);
        ListNode *t = &dummy;
        while (p && q) {
            if (p->val < q->val) {
                t->next = p;
                p = p->next;
            }
            else {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        t->next = p ? p : q;
        return dummy.next;
    }
};
