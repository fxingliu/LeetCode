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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort by start
        sort(intervals.begin(), intervals.end(), compareIntervals);
        for (int i=1; i<intervals.size(); i++)
            if (intervals[i].start < intervals[i-1].end) return false;
        return true;
    }
    
private:
    static bool compareIntervals(Interval a, Interval b) {
        return a.start < b.start;
    }
};
