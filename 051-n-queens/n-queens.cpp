// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


static const auto _= [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n,-1);
        DFS(res,pos,0,n);
        return res;
    }
    
    void DFS(vector<vector<string>>& res, vector<int>& pos, int i, int n){
        if(i==n){
            vector<string> tempres;
            for(const auto& p:pos){
                string temp;
                int j=0;
                for(;j<p;++j)
                    temp+='.';
                temp+='Q',++j;
                for(;j<n;++j)
                    temp+='.';
                tempres.push_back(temp);
            }
            res.push_back(tempres);
            return;
        }
        for(int k=0;k<n;++k){
            pos[i]=k;
            if(!isValid(pos,i,n)){
                pos[i]=-1;
                continue;
            }
            DFS(res,pos,i+1,n);
        }
        pos[i]=-1;
        return;
    }
    
    //用来判断当前位置是否合理
    bool isValid(vector<int>& pos, int i, int n){
        for(int k=0;k<i;++k){
            if(pos[k]==pos[i])
                return false;
            if((i-k)==abs(pos[i]-pos[k]))
                return false;
        }
        return true;
    }
    

};
