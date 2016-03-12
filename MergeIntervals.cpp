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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ret;
        for (auto& i : intervals) {
            if (ret.empty() || ret.back().end < i.start) ret.push_back(i);
            else if (ret.back().end < i.end) ret.back().end = i.end;
        }
        return ret;
    }
    
private:
    static bool comp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
