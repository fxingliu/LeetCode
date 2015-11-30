/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode dummy(0);
        RandomListNode *t = head, *cur = &dummy;
        unordered_map<RandomListNode*, RandomListNode*> m;
        while (t) {
            RandomListNode *tmp = new RandomListNode(t->label);
            cur->next = tmp;
            m[t] = tmp;
            t = t->next;
            cur = cur->next;
        }
        
        t = head, cur = &dummy;
        while (t) {
            if (t->random)
                cur->next->random = m[t->random];
            else
                // avoid implicit code
                cur->next->random = NULL;
            t = t->next;
            cur = cur->next;
        }
        
        return dummy.next;
        
    }
};
