class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> inDegree;
        queue<int> q;
        int count = 0;
        
        for (auto& i : prerequisites) inDegree[i.first]++;
        for (int i=0; i<numCourses; i++)
            if (inDegree[i] == 0) q.push(i);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto& i : prerequisites) 
                if (i.second == cur && --inDegree[i.first] == 0) q.push(i.first);
            count++;
        }
        return count == numCourses;
    }
};
