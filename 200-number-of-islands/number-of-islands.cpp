// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int h=grid.size(),w=grid[0].size();
        int res=0;
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                if(grid[i][j]=='1') ++res,DFS(grid,i,j,h,w);
            }
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j,int h, int w){
        grid[i][j]='0';
        if(i-1>=0&&grid[i-1][j]=='1')
            DFS(grid,i-1,j,h,w);
        if(i+1<h&&grid[i+1][j]=='1')
            DFS(grid,i+1,j,h,w);
        if(j-1>=0&&grid[i][j-1]=='1')
            DFS(grid,i,j-1,h,w);
        if(j+1<w&&grid[i][j+1]=='1')
            DFS(grid,i,j+1,h,w);
        return;
    }
    
};
