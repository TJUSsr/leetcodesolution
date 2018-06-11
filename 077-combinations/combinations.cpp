// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input:&nbsp;n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<=0||k==0||k>n) return res;
        vector<int> tempres;
        DFS(res,tempres,n,k,1);
        return res;
    }
private:
    void DFS(vector<vector<int>>& res, vector<int>& tempres, const int& n, const int& k, const int& i){
        if(tempres.size()==k){
            res.push_back(tempres);
            return;
        }
        if(i>n)
            return;
        tempres.push_back(i);
        DFS(res,tempres,n,k,i+1);
        tempres.pop_back();
        DFS(res,tempres,n,k,i+1);
        return;
    }
};
