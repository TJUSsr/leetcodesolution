//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tempstring;
        vector<string> res;
        if(n<=0)
            return res;
        DFS(res,tempstring,n,n);
        return res;
    }
private:
    void DFS(vector<string>& res, string& tempstring, int left, int right){
        if(left==0){
            for(int i=0;i<right;++i){
                tempstring+=')';
            }
            res.push_back(tempstring);
            for(int i=0;i<right;++i){
                tempstring.erase(tempstring.size()-1);
            }
            return;
        }
        else if(left==right){
            tempstring+='(';
            DFS(res,tempstring,left-1,right);
            tempstring.erase(tempstring.size()-1);
        }
        else if(left<right){
            tempstring+='(';
            DFS(res,tempstring,left-1,right);
            tempstring.erase(tempstring.size()-1);
            tempstring+=')';
            DFS(res,tempstring,left,right-1);
            tempstring.erase(tempstring.size()-1);
        }
        return;
    }
};
