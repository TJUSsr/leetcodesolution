// Given a string containing just the characters &#39;(&#39; and &#39;)&#39;, find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: &quot;(()&quot;
// Output: 2
// Explanation: The longest valid parentheses substring is &quot;()&quot;
//
//
// Example 2:
//
//
// Input: &quot;)()())&quot;
// Output: 4
// Explanation: The longest valid parentheses substring is &quot;()()&quot;
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool DP=true;
    int longestValidParentheses(string s) {
        if(s.size()<=1)
            return 0;
        int res=0;
        if(DP){
            vector<int> dp(s.size()+1,0);
            for(int i=1;i<=s.size();++i){
                int j=i-dp[i-1]-1;
                if(s[i-1]=='('||j-1<0||(s[i-1]==')'&&s[j-1]==')'))
                    dp[i]=0;
                else if(s[i-1]==')'&&s[j-1]=='('){
                    dp[i]=dp[i-1]+2+dp[j-1];
                    if(dp[i]>res)
                        res=dp[i];
                }
            }
        }else{
            stack<int> st;
            int start=0;
            for(int i=0;i<s.size();++i){
                if(s[i]=='('){
                    st.push(i);
                }else{
                    if(st.empty())
                        start=i+1;
                    else{
                        st.pop();
                        if(st.empty())
                            res=i-start+1>res?i-start+1:res;
                        else
                            res=i-st.top()>res?i-st.top():res;
                    }
                }
            }
        }
        return res;
    }
};
