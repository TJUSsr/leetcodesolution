// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Example:
//
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// Note: 
// You may assume k is always valid, 1 &le; k &le; input array&#39;s size for non-empty array.
//
// Follow up:
// Could you solve it in linear time?
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            while(!q.empty()&&q.front()<i-k+1) q.pop_front();
            while(!q.empty()&&nums[i]>=nums[q.back()]) q.pop_back();q.push_back(i);
            if(q.empty()) q.push_back(i);
            if(i<=k-2) continue;
            else res.push_back(nums[q.front()]);
        }
        return res;
    }
};
