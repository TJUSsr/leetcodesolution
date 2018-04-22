// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor&nbsp;will be&nbsp;32-bit&nbsp;signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [&minus;231, &nbsp;231 &minus; 1]. For the purpose of this problem, assume that your function returns 231 &minus; 1 when the division result&nbsp;overflows.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if(divisor==1)
            return dividend;
        int sign=1;
        if(dividend>0){
            dividend=-dividend;
        }else
            sign=-sign;
        if(divisor>0){
            divisor=-divisor;
        }else
            sign=-sign;
        int res = 0;
        while (dividend <= divisor) { 
            int temp = divisor, multiple = 1;
            while (temp<<1<0&&dividend <= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dividend -= temp;
            res += multiple;
        }
        if(dividend==divisor)
            ++res;
        return sign == 1 ? res : -res; 
    }
};
