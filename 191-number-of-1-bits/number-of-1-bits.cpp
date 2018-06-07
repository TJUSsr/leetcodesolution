// Write a function that takes an unsigned integer and returns the number of &#39;1&#39;&nbsp;bits it has (also known as the Hamming weight).
//
// Example 1:
//
//
// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
//
//
// Example 2:
//
//
// Input: 128
// Output: 1
// Explanation: Integer 128 has binary representation 00000000000000000000000010000000
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
            n&=(n-1);
            ++res;
        }
        return res;
    }
};
