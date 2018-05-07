// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//
// Note:
//
//
// 	Your returned answers (both index1 and index2) are not zero-based.
// 	You may assume that each input would have exactly one solution and you may not use the same element twice.
//
//
// Example:
//
//
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res={1,numbers.size()};
        while(res[0]<res[1]){
            if(numbers[res[0]-1]+numbers[res[1]-1]==target)
                return res;
            else if(numbers[res[0]-1]+numbers[res[1]-1]>target)
                --res[1];
            else
                ++res[0];
        }
        return res;
    }
};
