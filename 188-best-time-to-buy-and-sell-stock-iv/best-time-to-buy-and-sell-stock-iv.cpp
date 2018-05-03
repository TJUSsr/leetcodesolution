// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//
// Example 2:
//
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
// &nbsp;            Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//
//


class Solution {
public:
    int min(const int&a, const int &b){
        if(a<b)
            return a;
        else
            return b;
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<=1||k==0) return 0;
        k=min(k,prices.size()/2);
        vector<vector<int>> dp(2,vector<int>(2*k,0));
        for(int i=0;i<2*k;i+=2){
            dp[0][i]=INT_MIN;
        }
        int now=0,next=1;
        for(const auto& price:prices){
            dp[next][0]=max(dp[now][0],-price);
            dp[next][1]=max(dp[now][1],price+dp[now][0]);
            for(int i=1;i<k;++i){
                dp[next][2*i]=max(dp[now][2*i],-price+dp[now][2*i-1]);
                dp[next][2*i+1]=max(dp[now][2*i+1],price+dp[now][2*i]);
            }
            swap(now,next);
        }
        int res=0;
        for(int i=0;i<k;++i){
            res=dp[now][2*i+1]>res?dp[now][2*i+1]:res;
        }
        return res;
    }
};
