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
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
//
// Example 2:
//
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
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
