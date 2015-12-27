class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteStep(nums, nums.size());
    }
    
private:
    vector<vector<int>> permuteStep(vector<int>& nums, int step) {
        vector<vector<int>> ret;
        if (step == 0) {
            ret.push_back(vector<int>());
            return ret;
        }
        
        vector<vector<int>> lastStep = permuteStep(nums, step-1);
        for (vector<int>& last : lastStep) {
            for (int i=0; i<=last.size(); ++i) {
                last.insert(last.begin()+i, nums[step-1]);
                ret.push_back(last);
                last.erase(last.begin()+i);
            }   
        }
        return ret;
    }
};
