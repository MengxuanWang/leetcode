/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

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
    static bool comp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), comp); 
        Interval cur = intervals[0]; 
        for (int i=1; i<intervals.size(); i++) {
            Interval interval = intervals[i];
            if (interval.start <= cur.end) {
                cur.end = max(cur.end, interval.end); 
            } else {
                res.push_back(cur); 
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
};