// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//利用BFS的思想，实现O(N)的时间复杂度，常数的空间复杂度
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int level=0,l=0,r=0;
        int newl,newr,temp;
        while(1){
            newl=r+1;
            newr=-1;
            for(int i=l;i<=r;++i){
                temp=i+nums[i];
                if(newr==-1) newr=temp;
                else newr=newr>temp?newr:temp;
            }
            ++level;
            if(newr>=nums.size()-1)
                break;
            l=newl,r=newr;
        }
        return level;
    }
};
