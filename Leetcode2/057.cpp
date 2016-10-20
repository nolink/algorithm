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
        vector<Interval> ret;
        for(auto interval : intervals){
            if(newInterval.end < interval.start){
                ret.push_back(newInterval);
                newInterval = interval;
            }else if(newInterval.start > interval.end){
                ret.push_back(interval);
            }else{
                newInterval = Interval(min(interval.start, newInterval.start), max(interval.end, newInterval.end));
            }
        }
        ret.push_back(newInterval);
        return ret;
    }
};
