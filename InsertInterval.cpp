/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> left, right;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) left.push_back(intervals[i]);
            if (intervals[i].start > newInterval.end) right.push_back(intervals[i]);
        }
        if (left.size() + right.size() != intervals.size()) {
            newInterval.start = min(newInterval.start, intervals[left.size()].start);
            newInterval.end = max(newInterval.end, intervals[intervals.size()-1-right.size()].end);
        }
        left.push_back(newInterval);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
