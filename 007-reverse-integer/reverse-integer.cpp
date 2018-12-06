// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int reverse(int x) {
        int res=0,temp;
        while(x!=0){
            temp=res*10+x%10;
            if(temp/10!=res)
                return 0;
            res=temp;
            x/=10;
        }
        res=res>2147483647?0:res;
        res=res<-2147483647?0:res;
        return res;
    }
};
