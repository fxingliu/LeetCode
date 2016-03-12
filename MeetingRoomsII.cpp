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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, compare> pq;
        sort(intervals.begin(), intervals.end(), comp);
        for (auto& i : intervals) {
            if (!pq.empty() && pq.top().end <= i.start) {
                // merge into one room
                Interval top = pq.top();
                pq.pop();
                top.end = i.end;
                pq.push(top);
            }
            else pq.push(i);
        }
        return pq.size();
    }
    
private:
    // min heap sorted by end time
    struct compare {
        bool operator()(const Interval& a, const Interval& b) {
            return a.end > b.end;
        }
    };
    
    // sort the intervals by start time
    static bool comp(const Interval& a, const Interval& b) {
       return a.start < b.start;
    }
};
