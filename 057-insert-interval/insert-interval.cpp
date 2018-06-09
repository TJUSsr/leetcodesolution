// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int start_=newInterval.start,end_=newInterval.end;
        int ss=-2,se=-2,es=-2,ee=-2;
        for(int i=0;i<intervals.size();++i){
            if(start_>=intervals[i].start&&start_<=intervals[i].end){
                ss=i;
                se=i;
            }else if(i!=0&&i!=intervals.size()-1){
                if(start_<intervals[i].start&&start_>intervals[i-1].end) {ss=i-1;se=i;}
            }else if(i==0){
                if(start_<intervals[i].start) {ss=-1;se=0;}
                if(i==intervals.size()-1&&start_>intervals[i].end){ss=0;se=1;}
            }else if(i==intervals.size()-1){
                if(start_<intervals[i].start&&start_>intervals[i-1].end) {ss=i-1;se=i;}
                else if(start_>intervals[i].end){ss=i;se=i+1;}
            }
            if(end_>=intervals[i].start&&end_<=intervals[i].end){
                es=i;
                ee=i;
            }else if(i!=0&&i!=intervals.size()-1){
                if(end_<intervals[i].start&&end_>intervals[i-1].end) {es=i-1;ee=i;}
            }else if(i==0){
                if(end_<intervals[i].start) {es=-1;ee=0;}
                if(i==intervals.size()-1&&end_>intervals[i].end){es=0;ee=1;}
            }else if(i==intervals.size()-1){
                if(end_<intervals[i].start&&end_>intervals[i-1].end) {es=i-1;ee=i;}
                else if(end_>intervals[i].end){es=i;ee=i+1;}
            }
            if(ss!=-2&&se!=-2&&es!=-2&&ee!=-2)
                break;
        }
        if(ss==se&&es==ee&&ss==es)
            return intervals;
        int left=se,right=es;
        int min_,max_;
        vector<Interval> res(intervals.begin(),intervals.begin()+left);
        if(ss==-1||se==intervals.size()){
            min_=start_;
        }else{
            min_=min(start_,intervals[left].start);
        }
        if(es==-1||ee==intervals.size()){
            max_=end_;
        }else{
            max_=max(end_,intervals[right].end);
        }
        Interval toinsert(min_,max_);
        res.push_back(toinsert);
        res.insert(res.end(),intervals.begin()+right+1,intervals.end());
        return res;
    }
};
