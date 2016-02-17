class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses);
        vector<bool> current(numCourses);
        bool hasCycle = false;
        
        for (int i=0; i<numCourses; i++) 
            dfs(i, visited, current, prerequisites, hasCycle);
        return !hasCycle;
    }
    
private:
    void dfs(int i, vector<bool>& visited, vector<bool>& current, vector<pair<int, int>>& pre, bool& hasCycle) {
        if (current[i]) hasCycle = true;
        if (visited[i]) return;
        
        visited[i] = true;
        current[i] = true;
        for (auto& p : pre) 
            if (p.second == i) dfs(p.first, visited, current, pre, hasCycle);
        current[i] = false;
    }
};
