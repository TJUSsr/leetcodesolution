// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
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
