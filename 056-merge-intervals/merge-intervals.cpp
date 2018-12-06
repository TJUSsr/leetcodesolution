// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
struct cmp{
    bool operator()(const Interval&a, const Interval& b){
        if(a.start<b.start)
            return true;
        else
            return false;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(),intervals.end(),cmp());
        int n=intervals.size();
        for(int i=0;i<n;++i){
            int j=0;
            for(;j<res.size();++j){
                if(intervals[i].start<=res[j].end){
                    res[j].end=max(res[j].end,intervals[i].end);
                    break;
                }
            }
            if(j==res.size())
                res.push_back(intervals[i]);
        }
    return res;
    }
};
