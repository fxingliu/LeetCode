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
        if (!head) return NULL;
        
        RandomListNode *t = head;
        // insert the copy of each node after itself
        while (t) {
            RandomListNode *tmp = new RandomListNode(t->label);
            tmp->next = t->next;
            t->next = tmp;
            t = tmp->next;
        }
        
        // assign the random pointer
        t = head;
        while (t) {
            if (t->random)
                t->next->random = t->random->next;
            t = t->next->next;
        }
        
        // return the list of copy
        RandomListNode *newhead = head->next;
        t = newhead;
        while (t->next) {
            t->next = t->next->next;
            t = t->next;
        }
        return newhead;
    }
};
