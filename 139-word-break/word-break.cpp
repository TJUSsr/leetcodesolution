//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
//
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
//
//
//
// Return true because "leetcode" can be segmented as "leet code".
//
//
//
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
//


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
            return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();++i){
            for(int j=0;j<=i;++j){
                if(dp[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
