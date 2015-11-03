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
        if (lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        for (int i=0; i<lists.size(); i++) 
            if (lists[i]) 
                heap.push(lists[i]);
        ListNode dummy(0);
        ListNode *t = &dummy;
        while (!heap.empty()) {
            t->next = heap.top();
            heap.pop();
            t = t->next;
            if (t->next) 
                heap.push(t->next);
        }
        t->next = NULL;
        return dummy.next;
        
    }
    
private:
    struct compare {
        bool operator()(const ListNode *p, const ListNode *q) const {
            return p->val > q->val;
        }
    };
};
