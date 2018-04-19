//
// Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
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
