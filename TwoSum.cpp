class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i=0; i<numbers.size(); i++) {
            map[numbers[i]] = i;
        }
        for (int i=0; i<numbers.size(); i++) {
            int comp = target-numbers[i];
            if (map.find(comp) != map.end() && map[comp] > i) {
                ans.push_back(i+1);
                ans.push_back(map[comp] + 1);
                return ans;
            }
        }
    }
};
