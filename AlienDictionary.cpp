class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<pair<char, char>> dependency;
        buildGraph(words, dependency);
        
        unordered_map<char, int> inDegree;
        queue<char> q;
        string ret;
        for (auto& it : dependency) 
            inDegree[it.second]++;
        // make sure every character appears in the map
        for (auto& s : words)
            for (char& c : s)
                if (inDegree.find(c) == inDegree.end()) inDegree[c] = 0;
        for (auto& it : inDegree)
            if (it.second == 0) q.push(it.first);
            
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            ret += cur;
            for (auto& it : dependency) 
                if (it.first == cur) {
                    --inDegree[it.second];
                    if (inDegree[it.second] == 0) q.push(it.second);
                }
        }
        
        if (ret.size() == inDegree.size()) return ret;
        return string();
    }
    
private:
    void buildGraph(vector<string> words, vector<pair<char, char>>& dep) {
        if (words.empty()) return;
        int i=0, j=0;
        while (j < words.size()) {
            if (words[i][0] == words[j][0]) j++;
            else {
                dep.push_back(make_pair(words[i][0], words[j][0]));
                vector<string> new_words;
                for (int k=i; k<j; k++)
                    if (words[k].size() > 1) new_words.push_back(words[k].substr(1));
                buildGraph(new_words, dep);
                i = j;
            }
        }
        vector<string> new_words;
        for (int k=i; k<j; k++)
            if (words[k].size() > 1) new_words.push_back(words[k].substr(1));
        buildGraph(new_words, dep);
    }
};
