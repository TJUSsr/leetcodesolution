// A robot is located at the top-left corner of a m x n grid (marked &#39;Start&#39; in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked &#39;Finish&#39; in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input:
// [
// &nbsp; [0,0,0],
// &nbsp; [0,1,0],
// &nbsp; [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -&gt; Right -&gt; Down -&gt; Down
// 2. Down -&gt; Down -&gt; Right -&gt; Right
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),l=obstacleGrid[0].size();
        vector<vector <int>> dp(r+1,vector<int>(l+1,0));
        for(int i=1;i<=r;++i){
            for(int j=1;j<=l;++j){
                if(obstacleGrid[i-1][j-1]==0)
                    if(i==1&&j==1) dp[i][j]=1;
                    else dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        return dp[r][l];
    }
};
