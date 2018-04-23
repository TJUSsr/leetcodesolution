// Note: This is an extension of House Robber.
//
// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. 
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    typedef pair<bool,int> value;
    int rob1(vector<int>& nums,int st,int end) {
        int sz=end-st+1;
        vector<value> dp(sz+1,make_pair(false,0));
        dp[0].first=false;
        dp[0].second=0;
        for(int i=1;i<=sz;++i){
            if(dp[i-1].first){
                if(dp[i-2].second+nums[i-1+st]>dp[i-1].second){
                    dp[i].first=true;
                    dp[i].second=dp[i-2].second+nums[i-1+st];
                }else{
                    dp[i].first=false;
                    dp[i].second=dp[i-1].second;
                }
            }else{
                dp[i].first=true;
                dp[i].second=dp[i-1].second+nums[i-1+st];
            }
        }
        return dp[sz].second;
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int sz=nums.size()-1;
        return max(rob1(nums,0,sz-1),rob1(nums,1,sz));
    }
};
