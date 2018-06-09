// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
//
// 	Insert a character
// 	Delete a character
// 	Replace a character
//
//
// Example 1:
//
//
// Input: word1 = &quot;horse&quot;, word2 = &quot;ros&quot;
// Output: 3
// Explanation: 
// horse -&gt; rorse (replace &#39;h&#39; with &#39;r&#39;)
// rorse -&gt; rose (remove &#39;r&#39;)
// rose -&gt; ros (remove &#39;e&#39;)
//
//
// Example 2:
//
//
// Input: word1 = &quot;intention&quot;, word2 = &quot;execution&quot;
// Output: 5
// Explanation: 
// intention -&gt; inention (remove &#39;t&#39;)
// inention -&gt; enention (replace &#39;i&#39; with &#39;e&#39;)
// enention -&gt; exention (replace &#39;n&#39; with &#39;x&#39;)
// exention -&gt; exection (replace &#39;n&#39; with &#39;c&#39;)
// exection -&gt; execution (insert &#39;u&#39;)
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int& min(const int&a, const int&b){
        if(a<b)
            return a;
        else
            return b;
    }
    
    int min3(const int&a, const int&b,const int&c){
        int min=a;
        if(b<min)
            min=b;
        if(c<min)
            min=c;
        return min;
    }
    
    int abs(const int&a){
        if(a>=0)
            return a;
        else
            return -a;
    }
    
    int minDistance(string word1, string word2) {
        int l1=word1.size(),l2=word2.size();
        if(word1.empty()||word2.empty())
            return abs(word1.size()-word2.size());
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(word1[i-1]==word2[j-1]){
                    if(i==1&&j==1)
                        dp[i][j]=0;
                    else if(i==1)
                        dp[i][j]=j-1;
                    else if(j==1)
                        dp[i][j]=i-1;
                    else
                        dp[i][j]=dp[i-1][j-1];
                }else{
                    if(i==1&&j==1)
                        dp[i][j]=1;
                    else if(i==1)
                        dp[i][j]=dp[i][j-1]+1;
                    else if(j==1)
                        dp[i][j]=dp[i-1][j]+1;
                    else
                        dp[i][j]=min3(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);
                }
            }
        }
        return dp[l1][l2];
    }
};
