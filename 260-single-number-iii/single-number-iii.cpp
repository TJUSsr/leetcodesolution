//
// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//
// For example:
//
//
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
//
// Note:
//
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        if(nums.empty())
            return res;
        int temp=0;
        for(const auto&c:nums)
            temp^=c;
        if(!temp)
            return res;
		int index=0;
        temp&=-temp;
        for(const auto&c:nums){
            if(c&temp){
                res[0]^=c;
            }
            else{
                res[1]^=c;
            }
        }
        return res;
    }
};
