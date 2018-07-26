// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., &nbsp;[0,1,2,4,5,6,7]&nbsp;might become &nbsp;[4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
//
// Input: [3,4,5,1,2] 
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,5,6,7,0,1,2]
// Output: 0
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
        int left=0,right=nums.size()-1;
        if(nums[left]<nums[right])
            return nums[left];
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(nums[mid]==nums[left])
                left=mid+1;
            else if(nums[mid]<nums[left])
                right=mid;
            else
                left=mid;
        }
        return nums[right];
    }
};
