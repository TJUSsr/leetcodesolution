// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
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
    void DFS(vector<vector<int>>& res, vector<int>& nums, int i){
        if(i==nums.size())
            res.push_back(nums);
        unordered_set<int> has;
        for(int j=i;j<nums.size();++j){
            if(has.count(nums[j])==1)
                continue;
            has.insert(nums[j]);
            swap(nums[i],nums[j]);
            DFS(res,nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        DFS(res,nums,0);
        return res;
    }
};
