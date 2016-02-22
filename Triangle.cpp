class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int layer = triangle.size();
        if (layer == 0) return 0;
        if (layer == 1) return triangle[0][0];
        
        vector<int> dp((layer+1)*layer/2);
        dp[0] = triangle[0][0];
        int count = 1, ret = INT_MAX;
        
        for (int i=1; i<layer; i++) {
            dp[count] = dp[count-i] + triangle[i][0];
            for (int j=1; j<i; j++)
                dp[count+j] = min(dp[count+j-i-1], dp[count+j-i]) + triangle[i][j];
            dp[count+i] = dp[count-1] + triangle[i][i];
            
            if (i == layer-1) 
                for (int j=0; j<=i; j++) ret = min(ret, dp[count+j]);
                
            count += i+1;
        }
        return ret;
    }
};
