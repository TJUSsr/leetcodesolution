// Given an integer, write a function to determine if it is a power of two.
//
// Example 1:
//
//
// Input: 1
// Output: true 
// Explanation: 20 = 1
//
//
// Example 2:
//
//
// Input: 16
// Output: true
// Explanation: 24 = 16
//
// Example 3:
//
//
// Input: 218
// Output: false
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        while(n>1){
            auto y = n%2;
            if(y)
                return false;
            n=n>>1;
        }
        return true;
    }
};
