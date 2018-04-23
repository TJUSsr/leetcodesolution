// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.


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
