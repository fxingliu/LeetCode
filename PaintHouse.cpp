class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int r = costs[0][0], b = costs[0][1], g = costs[0][2];
        for (int i=1; i<costs.size(); i++) {
            int rr = r, bb = b, gg = g;
            r = min(bb, gg) + costs[i][0];
            b = min(rr, gg) + costs[i][1];
            g = min(rr, bb) + costs[i][2];
        }
        return min(min(r, b), g);
    }
};
