// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
// Example:
//
//
// Input:  [1,2,1,3,2,5]
// Output: [3,5]
//
// Note:
//
//
// 	The order of the result is not important. So in the above example, [5, 3] is also correct.
// 	Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
//


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
