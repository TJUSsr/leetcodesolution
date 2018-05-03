// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// &#39;A&#39; -&gt; 1
// &#39;B&#39; -&gt; 2
// ...
// &#39;Z&#39; -&gt; 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: &quot;12&quot;
// Output: 2
// Explanation:&nbsp;It could be decoded as &quot;AB&quot; (1 2) or &quot;L&quot; (12).
//
//
// Example 2:
//
//
// Input: &quot;226&quot;
// Output: 3
// Explanation:&nbsp;It could be decoded as &quot;BZ&quot; (2 26), &quot;VF&quot; (22 6), or &quot;BBF&quot; (2 2 6).
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        if(s[0]=='0')
            return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            int pre=s[i-2]-'0';
            int now=s[i-1]-'0';
            int sum=pre*10+now;
            if(sum%10==0&&(pre>=3||pre==0))
                return 0;
            else if(sum==10||sum==20)
                dp[i]=dp[i-2];
            else if(sum>10&&sum<=26)
                dp[i]=dp[i-2]+dp[i-1];
            else
                dp[i]=dp[i-1];
        }
        return dp[n];
    }
};
