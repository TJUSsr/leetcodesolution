// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=left+(right-left>>1);
            if(nums[mid]==target||nums[left]==target||nums[right]==target)
                return true;
            else if(nums[left]==nums[mid]&&nums[right]==nums[mid]){
                for(int i=left+1;i<=right-1;++i)
                    if(nums[i]==target)
                        return true;
                return false;
            }else if(nums[left]<nums[right])
                if(nums[mid]<target)
                    left=mid+1;
                else
                    right=mid-1;
            else if(nums[mid]<target&&nums[left]<nums[mid]||nums[mid]<target&&nums[right]>target||nums[mid]>=nums[left]&&nums[left]>target)
                left=mid+1;
            else
                right=mid-1;
        }
        return nums[mid]==target;
    }
};
