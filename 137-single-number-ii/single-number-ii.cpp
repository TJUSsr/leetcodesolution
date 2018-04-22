// Given a non-empty&nbsp;array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,3,2]
// Output: 3
//
//
// Example 2:
//
//
// Input: [0,1,0,1,0,1,99]
// Output: 99
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        int threes=0;
        for(size_t i=0;i<nums.size();++i){
            twos|=ones&nums[i];
            ones^=nums[i];
            threes=twos&ones;
            twos^=threes;
            ones^=threes;
        }
        return ones;
    }
};
