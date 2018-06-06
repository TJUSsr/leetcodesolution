// The n-queens puzzle is the problem of placing n queens on an n&times;n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens&#39; placement, where &#39;Q&#39; and &#39;.&#39; both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [&quot;.Q..&quot;,  // Solution 1
//   &quot;...Q&quot;,
//   &quot;Q...&quot;,
//   &quot;..Q.&quot;],
//
//  [&quot;..Q.&quot;,  // Solution 2
//   &quot;Q...&quot;,
//   &quot;...Q&quot;,
//   &quot;.Q..&quot;]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


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
