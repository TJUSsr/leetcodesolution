// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum &ge; s. If there isn&#39;t one, return 0 instead.
//
// Example:&nbsp;
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).&nbsp;
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0,right=0,n=nums.size(),sum=0,res=INT_MAX,tempsum=0,templeft=0;
        while(right<n){
            sum+=nums[right];
            if(sum>=s){
                while(left+1<=right&&sum-nums[left]>=s){
                    sum-=nums[left];
                    ++left;
                };
                res=res<right-left+1?res:right-left+1;
            }   
            ++right;
        }
        return res==INT_MAX?0:res;
    }
};
