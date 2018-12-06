// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h=board.size(),w=board[0].size();
        if(h==0||w==0) return false;
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        int len=word.size();
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                if(DFS(board,visited,word,0,len,i,j,h,w))
                    return true;
            }
        }
        return false;
    }
private:
    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, const int& i, const int& len, const int& x, const int& y, const int& h, const int& w){
        if(i>=len)
            return false;
        if(board[x][y]==word[i]){
            if(i==len-1)
                return true;
            visited[x][y]=true;
            if(x>=1&&visited[x-1][y]==false)
               if(DFS(board,visited,word,i+1,len,x-1,y,h,w))
                   return true;
            if(x<=h-2&&visited[x+1][y]==false)
                if(DFS(board,visited,word,i+1,len,x+1,y,h,w))
                    return true;
            if(y>=1&&visited[x][y-1]==false)
                if(DFS(board,visited,word,i+1,len,x,y-1,h,w))
                    return true;
            if(y<=w-2&&visited[x][y+1]==false)
                if(DFS(board,visited,word,i+1,len,x,y+1,h,w))
                    return true;
            visited[x][y]=false;
        }
        return false;
    }
};
