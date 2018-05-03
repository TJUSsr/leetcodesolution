// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and&nbsp;it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
// &nbsp;            because they are adjacent houses.
//
//
// Example 2:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// &nbsp;            Total amount you can rob = 1 + 3 = 4.
//


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
