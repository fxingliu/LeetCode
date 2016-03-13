class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        // deque contains the original index
        deque<int> dq;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            // the elements in queue is sorted by both sequence order and value
            if (i+1 >= k) ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
