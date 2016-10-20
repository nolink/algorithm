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
        vector<Interval> ret;
        if(intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return b.start > a.start;   
        });
        Interval extended = *intervals.begin();
        for(int i=1;i<intervals.size();i++){
            Interval current = intervals[i];
            if(current.start > extended.end){
                ret.push_back(extended);
                extended = current;
            }else{
                extended = Interval(min(current.start, extended.start), max(current.end, extended.end));
            }
        }
        ret.push_back(extended);
        return ret;
    }
};
