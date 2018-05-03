// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// &nbsp;            Total amount you can rob = 1 + 3 = 4.
//
// Example 2:
//
//
// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// &nbsp;            Total amount you can rob = 2 + 9 + 1 = 12.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    typedef pair<bool,int> value;
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sz=nums.size();
        vector<value> dp(sz+1,make_pair(false,0));
        dp[0].first=false;
        dp[0].second=0;
        for(int i=1;i<=sz;++i){
            if(dp[i-1].first){
                if(dp[i-2].second+nums[i-1]>dp[i-1].second){
                    dp[i].first=true;
                    dp[i].second=dp[i-2].second+nums[i-1];
                }else{
                    dp[i].first=false;
                    dp[i].second=dp[i-1].second;
                }
            }else{
                dp[i].first=true;
                dp[i].second=dp[i-1].second+nums[i-1];
            }
        }
        return dp[sz].second;
    }
};
