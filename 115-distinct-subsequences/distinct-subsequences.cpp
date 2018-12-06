// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
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
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
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
