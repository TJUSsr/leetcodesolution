// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<int> v(triangle.back());
        for(int layer=size-2;layer>=0;--layer){
            for(int i=0;i<=layer;++i){
                triangle[layer][i]=min(triangle[layer][i]+triangle[layer+1][i],triangle[layer][i]+triangle[layer+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};
