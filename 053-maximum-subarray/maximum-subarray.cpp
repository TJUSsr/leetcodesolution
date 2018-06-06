// Given an integer array nums, find the contiguous subarray&nbsp;(containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation:&nbsp;[4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return tradition(nums);
    }
    //传统方法
    int tradition(vector<int>& nums){
        int tempres=nums[0],res=nums[0];
        for(int i=1;i<nums.size();++i){
            if(tempres<0){
                tempres=nums[i];
            }else{
                tempres+=nums[i];
            }
            if(tempres>res)
                res=tempres;
        }
        return res;
    }
};
