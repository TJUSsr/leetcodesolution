// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int l=1,r=x/2;
        while(l<r){
            long long mid=l+((r-l+1)>>1);
            if(mid*mid==x) return mid;
            else if(mid*mid<x) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
