// Given an array, rotate the array to the right by k steps, where k is non-negative.
//
// Example 1:
//
//
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
//
// Example 2:
//
//
// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
//
//
// Note:
//
//
// 	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// 	Could you do it in-place with O(1) extra space?
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()||k%nums.size()==0) return;
        k%=nums.size();
        int count=0;
        for(int i=0;count<nums.size();++i){
            int start=i;
            int current=start,pre=current;
            int temp=nums[pre];
            do{
                current=(current+k)%nums.size();
                auto t1=nums[current];
                nums[current]=temp;
                temp=t1;
                ++count;
            }while(current!=start);
        }
        return;
    }
};
