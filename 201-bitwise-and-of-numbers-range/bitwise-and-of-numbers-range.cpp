// Given a range [m, n] where 0 &lt;= m &lt;= n &lt;= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
// Example 1:
//
//
// Input: [5,7]
// Output: 4
//
//
// Example 2:
//
//
// Input: [0,1]
// Output: 0
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m<n){
            n=n&(n-1);
        }
        return n;
    }
};
