class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        vector<int> num(n+1);
        
        for (int i=1; i*i<=n; i++) {
            square.push_back(i*i);
            num[i*i] = 1;
        }
        if (square.back() == n) return 1;
        
        queue<int> q;
        for (int& i : square) q.push(i);
        int count = 1;
        
        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int i=0; i<size; i++) {
                int cur = q.front();
                q.pop();
                
                for (int& j : square) {
                    if (cur+j == n) return count;
                    if (cur+j > n) break;
                    else if (cur+j < n && num[cur+j] == 0) {
                        num[cur+j] = count;
                        q.push(cur+j);
                    }
                }
            }
        }
        return 0;
    }
};
