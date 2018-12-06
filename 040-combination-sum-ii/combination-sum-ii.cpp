// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
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
    void DFS(vector<int>& candidates, vector<int>& tempres, vector<vector<int>>& res, int target, int order,int sum){
        for(int i=order;i<candidates.size()&&target>=sum&&target>=candidates[i];++i){
            if(i&&candidates[i]==candidates[i-1]&&i>order) continue;
            tempres.push_back(candidates[i]);
            sum+=candidates[i];
            if(sum==target)
                res.push_back(tempres);
            DFS(candidates,tempres,res,target,i+1,sum);
            sum-=candidates[i];
            tempres.pop_back();
        }
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        sort(candidates.begin(),candidates.end());
        vector<int> tempres;
        int sum=0;
        DFS(candidates,tempres,res,target,0,sum);
        return  res;
    }
};
