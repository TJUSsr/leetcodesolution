// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//
//


class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,0);
        for(int i=0;i<=s.size();++i)
            dp[i]=i-1;
        for(int i=1;i<s.size();++i){
            for(int j=0;i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j];++j)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j]+1);
            for(int j=0;i-j-1>=0&&i+j<s.size()&&s[i-j-1]==s[i+j];++j)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j-1]+1);
        }
        return dp[s.size()];
    }
    /*动态规划，维护一个dp记录每一个子字符串的mincut，一个matrix记录j到i之间是否是回文。
    int minCut(string s) {
        vector<int> dp(s.size()+1,0);
        for(int i=0;i<=s.size();++i)
            dp[i]=i-1;
        vector<vector<bool> > matrix(s.size()+1, vector<bool>(s.size()+1, false));
        for(int i=1;i<s.size();++i){
            for(int j=i;j>=0;--j){
                if(s[i]==s[j]&&(i-j<2||matrix[j+1][i-1])){
                    dp[i+1]=min(dp[i+1],1+dp[j]);
                    matrix[j][i]=true;
                }
            }
        }
        return dp[s.size()];
    }*/
};
