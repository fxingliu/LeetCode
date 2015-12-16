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
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        m[node] = new_node;
        
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for (UndirectedGraphNode *neighbor : cur->neighbors) {
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                m[cur]->neighbors.push_back(m[neighbor]);
            }
        }
        return new_node;
    }
};
