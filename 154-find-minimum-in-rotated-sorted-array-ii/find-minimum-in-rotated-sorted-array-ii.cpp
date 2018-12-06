// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// The array may contain duplicates.
//
// Example 1:
//
//
// Input: [1,3,5]
// Output: 1
//
// Example 2:
//
//
// Input: [2,2,2,0,1]
// Output: 0
//
// Note:
//
//
// 	This is a follow up problem to Find Minimum in Rotated Sorted Array.
// 	Would allow duplicates affect the run-time complexity? How and why?
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        if(nums[left]<nums[right]||left==right) return nums[left];
        while(left<=right){
            mid=left+(right-left>>1);
            if(mid==left)
                break;
            else if(nums[left]==nums[mid]&&nums[right]==nums[mid])
                break;
            else if(nums[mid]>=nums[left])
                left=mid;
            else if(nums[mid]<=nums[left])
                right=mid;
        }
        if(nums[left]==nums[mid]&&nums[right]==nums[mid])
            for(int i=left+1;i<=right-1;++i){
                if(nums[i]<nums[i-1])
                    return nums[i];
            }
        return nums[right];
    }
};
