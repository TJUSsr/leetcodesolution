// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input: s = &quot;leetcode&quot;, wordDict = [&quot;leet&quot;, &quot;code&quot;]
// Output: true
// Explanation: Return true because &quot;leetcode&quot; can be segmented as &quot;leet code&quot;.
//
//
// Example 2:
//
//
// Input: s = &quot;applepenapple&quot;, wordDict = [&quot;apple&quot;, &quot;pen&quot;]
// Output: true
// Explanation: Return true because &quot;applepenapple&quot; can be segmented as &quot;apple pen apple&quot;.
// &nbsp;            Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input: s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;, &quot;dog&quot;, &quot;sand&quot;, &quot;and&quot;, &quot;cat&quot;]
// Output: false
//
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
