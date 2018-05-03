// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
// &nbsp; [1],
// &nbsp; [2],
// &nbsp; [1,2,3],
// &nbsp; [1,3],
// &nbsp; [2,3],
// &nbsp; [1,2],
// &nbsp; []
// ]
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void DFS(vector<vector<int>>& res, vector<int>& tempres,vector<int>& nums, int i){
        if(i==nums.size()){
            res.push_back(tempres);
            return;
        }
        DFS(res,tempres,nums,i+1);
        tempres.push_back(nums[i]);
        DFS(res,tempres,nums,i+1);
        tempres.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempres;
        DFS(res,tempres,nums,0);
        return res;
    }
};
