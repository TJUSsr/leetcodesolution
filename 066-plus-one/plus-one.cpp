// Given a non-empty array of digits&nbsp;representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow=1;
        for(int i=digits.size()-1;i>=0;--i){
            digits[i]+=overflow;
            overflow=digits[i]==10?1:0;
            digits[i]=digits[i]==10?0:digits[i];
        }
        if(overflow)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
