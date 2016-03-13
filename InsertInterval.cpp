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
        const int n = intervals.size();
        if (n == 0) return vector<Interval>{newInterval};
        int left = binarySearchLeft(intervals, newInterval, 0, n-1);
        int right = binarySearchRight(intervals, newInterval, 0, n-1);
        if (right-left > 1) {
            // overlap exists from [left+1] to [right-1]
            newInterval.start = min(newInterval.start, intervals[left+1].start);
            newInterval.end = max(newInterval.end, intervals[right-1].end);
            intervals.erase(intervals.begin()+left+1, intervals.begin()+right);
        }
        intervals.insert(intervals.begin()+left+1, newInterval);
        return intervals;
    }
    
private:
    // search for intervals strictly left of newInterval
    int binarySearchLeft(vector<Interval>& intervals, Interval newInterval, int left, int right) {
        int L = left, R = right, M;
        while (L < R) {
            M = (L+R)/2;
            if (intervals[M].end < newInterval.start) L = M+1;
            else R = M;
        }
        return intervals[L].end >= newInterval.start ? L-1 : L;
    }
    
    // search for intervals strictly right of newInterval
    int binarySearchRight(vector<Interval>& intervals, Interval newInterval, int left, int right) {
        int L = left, R = right, M;
        while (L < R) {
            M = (L+R)/2;
            if (intervals[M].start > newInterval.end) R = M;
            else L = M+1;
        }
        return intervals[L].start <= newInterval.end ? L+1 : L;
    }
};
