// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm&#39;s runtime complexity must be in the order of&nbsp;O(log&nbsp;n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left=0,right=nums.size()-1,mid;
        while(left<right){
            mid=left+(right-left>>1);
            //cout<<"left:"<<left<<" mid:"<<mid<<" right:"<<right<<endl;
            if(nums[mid]==target)
                return mid;
            else if(nums[left]==target)
                return left;
            else if(nums[right]==target)
                return right;
            else if(nums[mid]<target){
                if(nums[left]<nums[right]||nums[left]<nums[mid]||target<nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }else{
                if(nums[left]<nums[right]||nums[left]>nums[mid]||target>nums[left])
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        if(nums[left]==target)
            return left;
        else
            return -1;
    }
};
