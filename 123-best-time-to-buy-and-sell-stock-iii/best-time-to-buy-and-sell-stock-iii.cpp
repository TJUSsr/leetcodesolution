// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note:&nbsp;You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// &nbsp;            Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
//
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// &nbsp;            Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
// &nbsp;            engaging multiple transactions at the same time. You must sell before buying again.
//
//
// Example 3:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<vector<int>> dp(2,vector<int>(4,0));
        int now=0,next=1;
        dp[now][0]=INT_MIN;
        dp[now][2]=INT_MIN;
        int sz=prices.size()-1;
        for(int i=0;i<=sz;++i){
            dp[next][0]=max(dp[now][0],-prices[i]);
            dp[next][1]=max(dp[now][1],prices[i]+dp[now][0]);
            dp[next][2]=max(dp[now][2],dp[now][1]-prices[i]);
            dp[next][3]=max(dp[now][3],prices[i]+dp[now][2]);
            int temp=now;
            now=next;
            next=temp;
        }
        return max(dp[now][1],dp[now][3]);
    }
};
