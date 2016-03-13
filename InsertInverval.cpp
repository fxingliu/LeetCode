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
        list<Interval> ret(intervals.begin(), intervals.end());
        list<Interval>::iterator it = ret.begin(), newIt, prev;
        // insert by the order of start time
        for (; it != ret.end(); it++) 
            if (newInterval.start <= it->start) {
                newIt = ret.insert(it, newInterval);
                break;
            }
        if (it == ret.end()) newIt = ret.insert(it, newInterval);
        
        // merge with the previous interval
        if (newIt != ret.begin()) {
            prev = newIt;
            prev--;
            if (prev->end >= newIt->start) {
                newIt->start = prev->start;
                newIt->end = max(newIt->end, prev->end);
                ret.erase(prev);
            }
        }
        // merge with following intervals
        for (; next(newIt) != ret.end(); it++) {
            if (newIt->end < it->start) break;
            newIt->end = max(newIt->end, it->end);
            ret.erase(it);
            it = newIt;
        }
        return vector<Interval>(ret.begin(), ret.end());
    }
};
