// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Example 1:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
//
//
// Example 2:
//
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
//
//


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.empty())
            return 0;
        if(points.size()<=2)
            return points.size();
        int res=0;
        for(int i=0;i<points.size();++i){
            int curMax=0;
            int curOverlap=0;
            map<pair<int,int>,int> hash;
            for(int j=i+1;j<points.size();++j){
                if(points[i].x==points[j].x&&points[i].y==points[j].y){
                    ++curOverlap;
                }
                else{
                    int diffx=points[i].x-points[j].x;
                    int diffy=points[i].y-points[j].y;
                    int g=__gcd(diffx,diffy);
                    diffx/=g;
                    diffy/=g;
                    curMax=max(curMax,++hash[make_pair(diffx,diffy)]);
                }
            }
            res=max(res,curMax+curOverlap+1);
        }
        return res;
    }
};
