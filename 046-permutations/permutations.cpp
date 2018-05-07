// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
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
    void DFS(vector<vector<int>>& res,vector<int>& nums, int i){
        if(i==nums.size())
            res.push_back(nums);
        for(int j=i;j<nums.size();++j){
            swap(nums[i],nums[j]);
            DFS(res,nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        DFS(res,nums,0);
        return res;
    }
};
