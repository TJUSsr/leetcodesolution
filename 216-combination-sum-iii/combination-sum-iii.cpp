//
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
// Note:
//
//
// 	All numbers will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: k = 3, n = 7
// Output: [[1,2,4]]
//
//
// Example 2:
//
//
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
//
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tempres;
        DFS(res,tempres,0,0,k,n);
        return res;
    }
private:
    void DFS(vector<vector<int>>& res, vector<int>& tempres, int i,int sum, int k, int n){
        if(i==k){
            if(sum==n)
                res.push_back(tempres);
            return;
        }
        for(int j=i+1;j<=9;++j){
            tempres.push_back(j);
            sum+=j;
            if(sum<=n&&(i==0||j>tempres[i-1]))
                DFS(res,tempres,i+1,sum,k,n);
            sum-=j;
            tempres.pop_back();
        }
        return;
    }
};
