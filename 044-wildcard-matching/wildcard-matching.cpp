// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for &#39;?&#39; and &#39;*&#39;.
//
//
// &#39;?&#39; Matches any single character.
// &#39;*&#39; Matches any sequence of characters (including the empty sequence).
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s&nbsp;could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like ?&nbsp;or&nbsp;*.
//
//
// Example 1:
//
//
// Input:
// s = &quot;aa&quot;
// p = &quot;a&quot;
// Output: false
// Explanation: &quot;a&quot; does not match the entire string &quot;aa&quot;.
//
//
// Example 2:
//
//
// Input:
// s = &quot;aa&quot;
// p = &quot;*&quot;
// Output: true
// Explanation:&nbsp;&#39;*&#39; matches any sequence.
//
//
// Example 3:
//
//
// Input:
// s = &quot;cb&quot;
// p = &quot;?a&quot;
// Output: false
// Explanation:&nbsp;&#39;?&#39; matches &#39;c&#39;, but the second letter is &#39;a&#39;, which does not match &#39;b&#39;.
//
//
// Example 4:
//
//
// Input:
// s = &quot;adceb&quot;
// p = &quot;*a*b&quot;
// Output: true
// Explanation:&nbsp;The first &#39;*&#39; matches the empty sequence, while the second &#39;*&#39; matches the substring &quot;dce&quot;.
//
//
// Example 5:
//
//
// Input:
// s = &quot;acdcb&quot;
// p = &quot;a*c?b&quot;
// Output: false
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isMatch(string s, string p) {
        int lens=s.size(),lenp=p.size();
        vector<vector<bool>> dp(lens+1,vector<bool>(lenp+1,false));
        dp[0][0]=true;
        for(int i=1;i<=lenp;++i){
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<=lens;++i){
            for(int j=1;j<=lenp;++j){
                if(p[j-1]!='*'){
                    if(s[i-1]==p[j-1]||p[j-1]=='?')
                        dp[i][j]=dp[i-1][j-1];
                }else{
                    //此处为重点
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
            }
        }
        return dp[lens][lenp];
    }
};
