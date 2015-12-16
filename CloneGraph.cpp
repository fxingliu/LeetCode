/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // old node ptr -> new node ptr
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return clone(node, m);
    }
    
private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m) {
        if (!node) return NULL;
        if (m.find(node) != m.end())
            return m[node];
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        m[node] = newnode;
        for (UndirectedGraphNode *neighbor : node->neighbors) {
            UndirectedGraphNode *new_neighbor = clone(neighbor, m);
            newnode->neighbors.push_back(new_neighbor);
        }
        return newnode;
    }
};
