// Given an integer n, return the number of trailing zeroes in n!.
//
// Example 1:
//
//
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
//
// Example 2:
//
//
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
//
// Note: Your solution should be in logarithmic time complexity.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(long long i=5;n/i!=0;i*=5){
            res+=(n/i);
        }
        return res;
    }
};
