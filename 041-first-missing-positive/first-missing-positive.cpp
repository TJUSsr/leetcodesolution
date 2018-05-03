// Given an unsorted integer array, find the smallest missing&nbsp;positive integer.
//
// Example 1:
//
//
// Input: [1,2,0]
// Output: 3
//
//
// Example 2:
//
//
// Input: [3,4,-1,1]
// Output: 2
//
//
// Example 3:
//
//
// Input: [7,8,9,11,12]
// Output: 1
//
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(i<n){
            if(nums[i]>=1&&nums[i]<=n&&nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
                int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
            }else
                ++i;
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
