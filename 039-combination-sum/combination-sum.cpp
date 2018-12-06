// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
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
    void DFS(vector<int>& candidates, vector<int>& tempres, vector<vector<int>>& res, int target, int i,int sum){
        if(i==candidates.size())
            return;
        for(;i<candidates.size()&&target>=sum&&target>=candidates[i];++i){
            tempres.push_back(candidates[i]);
            sum+=candidates[i];
            if(sum==target)
                res.push_back(tempres);
            DFS(candidates,tempres,res,target,i,sum);
            sum-=candidates[i];
            tempres.pop_back();
        }
        return;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        sort(candidates.begin(),candidates.end());
        vector<int> tempres;
        int sum=0;
        DFS(candidates,tempres,res,target,0,sum);
        return res;
    }
};
