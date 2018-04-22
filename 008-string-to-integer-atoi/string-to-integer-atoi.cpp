// Implement atoi which&nbsp;converts a string to an integer.
//
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned.
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [&minus;231,&nbsp; 231&nbsp;&minus; 1]. If the numerical value is out of the range of representable values, INT_MAX (231&nbsp;&minus; 1) or INT_MIN (&minus;231) is returned.
//
// Example 1:
//
//
// Input: &quot;42&quot;
// Output: 42
//
//
// Example 2:
//
//
// Input: &quot;   -42&quot;
// Output: -42
// Explanation: The first non-whitespace character is &#39;-&#39;, which is the minus sign.
// &nbsp;            Then take as many numerical digits as possible, which gets 42.
//
//
// Example 3:
//
//
// Input: &quot;4193 with words&quot;
// Output: 4193
// Explanation: Conversion stops at digit &#39;3&#39; as the next character is not a numerical digit.
//
//
// Example 4:
//
//
// Input: &quot;words and 987&quot;
// Output: 0
// Explanation: The first non-whitespace character is &#39;w&#39;, which is not a numerical 
// &nbsp;            digit or a +/- sign. Therefore no valid conversion could be performed.
//
// Example 5:
//
//
// Input: &quot;-91283472332&quot;
// Output: -2147483648
// Explanation: The number &quot;-91283472332&quot; is out of the range of a 32-bit signed integer.
// &nbsp;            Thefore INT_MIN (&minus;231) is returned.
//


static auto static_lambda = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int i=0,j=str.size()-1;
        while(i<=str.size()-1&&str[i]==' ') ++i;
        if(i==str.size())
            return 0;
        while(j>=0&&str[j]==' ') --j;
        int res=0,ans,sign=1;
        if(str[i]=='+'||str[i]=='-')
            sign=(str[i++]=='+')?1:-1;
        for(int mark=i;mark<=j;++mark){
            if(str[mark]<'0'||str[mark]>'9')
                return res;          
            ans=res;
            res=res*10+sign*(str[mark]-48);
            if(res/10!=ans)
                return ans>0?2147483647:-2147483648;
        }
        return res;
    }
};
