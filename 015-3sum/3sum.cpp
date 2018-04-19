// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<=2)
            return res;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-2){
            if(nums[i]>0) break;
            int target=-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j+1]==nums[j])++j;
                    while(k>j&&nums[k-1]==nums[k])--k;
                    ++j;
                    --k;    
                }else if(nums[j]+nums[k]>target)--k;
                else ++j;
            }
            while(i+1<nums.size()-2&&nums[i+1]==nums[i])++i;
            ++i;
        }
        return res;
    }
};
