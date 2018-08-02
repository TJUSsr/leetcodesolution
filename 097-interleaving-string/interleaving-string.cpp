// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
//
// Input: s1 = &quot;aabcc&quot;, s2 = &quot;dbbca&quot;, s3 = &quot;aadbbcbcac&quot;
// Output: true
//
//
// Example 2:
//
//
// Input: s1 = &quot;aabcc&quot;, s2 = &quot;dbbca&quot;, s3 = &quot;aadbbbaccc&quot;
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
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
        if(len3!=len1+len2) return false;
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
        dp[0][0]=true;
        for(int len=1;len<=len3;++len){
            for(int i=min(len,len1);i>=0;--i){
                int j=len-i;
                if(j<=len2&&s1[i-1]==s3[len-1])
                    dp[i][j]=dp[i][j]||dp[i-1][j];
            }
            for(int j=min(len,len2);j>=0;--j){
                int i=len-j;
                if(i<=len1&&s2[j-1]==s3[len-1])
                    dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
        return dp[len1][len2];
    }
};
