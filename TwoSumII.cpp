class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i=0; i<numbers.size(); i++) {
            int ind2 = bst(numbers, i+1, target-numbers[i]);
            if (ind2 != -1) {
                ans.push_back(i+1);
                ans.push_back(ind2+1);
                return ans;
            }
        }
    }

private:
    int bst(const vector<int>& numbers, int start, int val) {
        int end = numbers.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (numbers[mid] < val)
                start = mid + 1;
            else
                end = mid;
        }
        return (start == end && numbers[start] == val) ? start : -1;
    }
};
