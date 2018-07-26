// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, &quot;ACE&quot; is a subsequence of &quot;ABCDE&quot; while &quot;AEC&quot; is not).
//
// Example 1:
//
//
// Input: S = &quot;rabbbit&quot;, T = &quot;rabbit&quot;
// Output:&nbsp;3
// Explanation:
//
// As shown below, there are 3 ways you can generate &quot;rabbit&quot; from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// Example 2:
//
//
// Input: S = &quot;babgbag&quot;, T = &quot;bag&quot;
// Output:&nbsp;5
// Explanation:
//
// As shown below, there are 5 ways you can generate &quot;bag&quot; from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        vector<vector<int>> dp(lent+1,vector<int>(lens+1,0));
        for(int i=1;i<=lent;++i){
            for(int j=i;j<=lens;++j){
                if(i==1){
                    t[i-1]==s[j-1]?dp[i][j]=dp[i][j-1]+1:dp[i][j]=dp[i][j-1];
                }else if(i==j){
                    if(t[i-1]==s[j-1]&&dp[i-1][j-1]==1) dp[i][j]=1;           
                    else dp[i][j]=0;
                }else{
                    dp[i][j]=(t[i-1]==s[j-1]?dp[i-1][j-1]+dp[i][j-1]:dp[i][j-1]);
                }
            }
        }
        return dp[lent][lens];
    }
};
