class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        // 0: not visited, 1: visited, -1: visiting
        vector<int> visited(numCourses, 0);
        vector<int> ret;
        bool hasCycle = false;
        
        buildGraph(graph, prerequisites);
        for (int i=0; i<numCourses; i++)
            dfs(i, graph, visited, ret, hasCycle);
            
        if (hasCycle) return vector<int>();
        return ret;
    }
    
private:
    void buildGraph(vector<unordered_set<int>>& graph, vector<pair<int, int>>& pre) {
        for (auto& p : pre) {
            // avoid duplicate
            if (!graph[p.second].count(p.first)) graph[p.second].insert(p.first);
        }
    }
    
    void dfs(int i, vector<unordered_set<int>>& graph, vector<int>& visited, vector<int>& ret, bool& hasCycle) {
        if (visited[i] == -1) hasCycle = true;
        else if (visited[i] == 0) {
            visited[i] = -1;
            for (auto it=graph[i].begin(); it!=graph[i].end(); it++) 
                dfs(*it, graph, visited, ret, hasCycle);
            visited[i] = 1;
            ret.insert(ret.begin(), i);
        }
    }
};
