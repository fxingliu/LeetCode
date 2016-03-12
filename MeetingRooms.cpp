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
        try {
            sort(intervals.begin(), intervals.end(), compareIntervals);
        }
        catch (exception& e) {
            return false;
        }
        return true;
    }
    
private:
    static bool compareIntervals(Interval a, Interval b) {
        if (a.start < b.start && a.end <= b.start) return true;
        if (a.start > b.start && a.start >= b.end) return false;
        throw exception();
    }
};
