//
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//
//
// For example,
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
//
//
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//


class Solution {
private:
    int row;
    int col; 
    void dfs(int i, int j, vector<vector<char>> &board){
        if(board[i][j]=='O'){
            board[i][j]='#';
            if(i>1){
                dfs(i-1,j,board);
            }
            if(i+1<row){
                dfs(i+1,j,board);
            }
            if(j>1){
                dfs(i,j-1,board);
            }
            if(j+1<col){
                dfs(i,j+1,board);
            }
        }
        else 
            return;
    }
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()||board[0].empty())
            return;
        //贴边找0，并转化为*
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;++i){
            dfs(i,0,board);
            dfs(i,col-1,board);
        }
        for(int j=1;j<col;++j){
            dfs(0,j,board);
            dfs(row-1,j,board);
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
