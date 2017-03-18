/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    static bool comp(const Interval& interval1, const Interval& interval2) {
        return interval1.start < interval2.start;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res; 
        if (intervals.size() == 0) {
            res.push_back(newInterval); 
            return res;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int insertPos = 0;
        for (int i=0; i<intervals.size(); i++) {
            Interval interval = intervals[i];
            if (interval.end < newInterval.start) {
                res.push_back(interval);
                insertPos ++;
            } 
            else if (interval.start > newInterval.end) {
                res.push_back(interval);
            }
            else {
                newInterval.start = min(newInterval.start, interval.start); 
                newInterval.end = max(newInterval.end, interval.end);
            }
        }
        
        res.insert(res.begin() + insertPos, newInterval);
        return res;
    }
};