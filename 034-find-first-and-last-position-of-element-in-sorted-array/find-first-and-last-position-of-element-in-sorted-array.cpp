// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        if(nums.empty())
            return res;
        int left=0,right=nums.size()-1,mid,mark=nums.size()-1;
        while(left<right){
            mid=left+((right-left)>>1);
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid;
                mark=right;
            }else
                right=mid;

        }
        if(nums[right]==target)
            res[0]=right;
        else{
            return res;
        }
        right=mark;
        while(left<right){
            mid=left+((right-left+1)>>1);
            if(nums[mid]<=target)
                left=mid;
            else
                right=mid-1;
        }
        res[1]=left;
        return res;
    }
};
