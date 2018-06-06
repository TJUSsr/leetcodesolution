// The n-queens puzzle is the problem of placing n queens on an n&times;n chessboard such that no two queens attack each other.
//
//
//
// Given an integer&nbsp;n, return the number of&nbsp;distinct solutions to the&nbsp;n-queens puzzle.
//
// Example:
//
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
// &nbsp;[&quot;.Q..&quot;, &nbsp;// Solution 1
// &nbsp; &quot;...Q&quot;,
// &nbsp; &quot;Q...&quot;,
// &nbsp; &quot;..Q.&quot;],
//
// &nbsp;[&quot;..Q.&quot;, &nbsp;// Solution 2
// &nbsp; &quot;Q...&quot;,
// &nbsp; &quot;...Q&quot;,
// &nbsp; &quot;.Q..&quot;]
// ]
//
//


static const auto _= [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<int> pos(n,-1);
        DFS(res,pos,0,n);
        return res;
    }
    
    void DFS(int& res, vector<int>& pos, int i, int n){
        if(i==n){
            ++res;
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
