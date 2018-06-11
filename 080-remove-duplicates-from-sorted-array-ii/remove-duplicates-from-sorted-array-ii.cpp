// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most&nbsp;twice and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// Example 1:
//
//
// Given nums = [1,1,1,2,2,3],
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//
// It doesn&#39;t matter what you leave beyond the returned length.
//
// Example 2:
//
//
// Given nums = [0,0,1,1,1,1,2,3,3],
//
// Your function should return length = 7, with the first seven elements of nums being modified to&nbsp;0, 0, 1, 1, 2, 3 and&nbsp;3 respectively.
//
// It doesn&#39;t matter what values are set beyond&nbsp;the returned length.
//
//
// Clarification:
//
// Confused why the returned value is an integer but your answer is an array?
//
// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
// Internally you can think of this:
//
//
// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);
//
// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i &lt; len; i++) {
// &nbsp; &nbsp; print(nums[i]);
// }
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int left=0,right=0,size=nums.size()-1;
        while(right<=size){
            left=right;
            int count=1,number=nums[right];
            while(right<=size-1&&nums[right+1]==number){
                ++right;
                ++count;
            }
            if(count<=2){
                ++right;
            }else
                break;
        }
        right=left;
        while(right<=size){
            int count=1,number=nums[right];
            while(right<=size-1&&nums[right+1]==number){
                ++right;
                ++count;
            }
            if(count>=2){
                nums[left++]=number;
            }
            nums[left++]=number;
            ++right;
        }
        return left;
    }
};
