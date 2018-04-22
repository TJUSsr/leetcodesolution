// Given an array nums of n integers and an integer target, find three integers in nums&nbsp;such that the sum is closest to&nbsp;target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long diff=INT_MAX,tempdiff,res,tempres;
        if(nums.size()<3)
            return 0;
        if(nums.size()==3)
            return nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int i=0,sz=nums.size();
        while(i<sz-2){
            if(i<sz-2&&nums[i]+nums[i+1]+nums[i+2]-diff>target) break;
            while(i<sz-2&&nums[i]+nums[sz-2]+nums[sz-1]+diff<target) ++i;
            int j=i+1,k=sz-1;
            while(j<k){
                if(j<k&&nums[i]+nums[j]+nums[j+1]-diff>target) break;
                while(j<k&&nums[i]+nums[j]+nums[sz-1]+diff<target) ++j;
                tempres=nums[i]+nums[j]+nums[k];
                if(tempres==target) 
                    return target;
                else if(tempres<target) 
                    ++j;
                else 
                    --k;
                tempdiff=target-tempres;
                tempdiff=tempdiff>=0?tempdiff:-tempdiff;
                if(tempdiff<diff){
                    diff=tempdiff;
                    res=tempres;
                }
 
            }
            while(i<sz-2&&nums[i+1]==nums[i]) ++i;
            ++i;
        }
        return res;
    }
};
