// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()<=3)
            return res;
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int sz=nums.size();
        while(i<sz-3){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            while(i<sz-3&&nums[i]+nums[sz-3]+nums[sz-2]+nums[sz-1]<target) ++i;
            j=i+1;
            while(j<sz-2){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                while(j<sz-2&&nums[i]+nums[j]+nums[sz-2]+nums[sz-1]<target) ++j;
                int k=j+1;
                int l=sz-1;
                while(k<l){
                    if(nums[k]+nums[l]==target-nums[j]-nums[i]){
                        res.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        while(k<l&&nums[k+1]==nums[k])++k;
                        while(k<l&&nums[l-1]==nums[l])--l;
                        ++k;
                        --l;
                    }else if(nums[k]+nums[l]>target-nums[j]-nums[i])--l;
                    else ++k;
                }
                while(j+1<nums.size()-2&&nums[j+1]==nums[j]) ++j;
                ++j;
            }
            while(i+1<nums.size()-3&&nums[i+1]==nums[i]) ++i;
            ++i;
        }
        return res;
    }
};
