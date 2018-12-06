// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h=grid.size(),w=grid[0].size();
        vector<vector<int>> dp(h+1,vector<int>(w+1,9999));
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                if(i==1&&j==1) dp[i][j]=grid[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[h][w];
    }
};
