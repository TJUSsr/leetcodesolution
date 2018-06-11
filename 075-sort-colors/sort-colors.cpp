// Given an array with n objects colored red, white or blue, sort them in-place&nbsp;so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note:&nbsp;You are not suppose to use the library&#39;s sort function for this problem.
//
// Example:
//
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
// Follow up:
//
//
// 	A rather straight forward solution is a two-pass algorithm using counting sort.
// 	First, iterate the array counting number of 0&#39;s, 1&#39;s, and 2&#39;s, then overwrite array with total number of 0&#39;s, then 1&#39;s and followed by 2&#39;s.
// 	Could you come up with a&nbsp;one-pass algorithm using only constant space?
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int left=0,right=0,size=nums.size()-1;
        for(int i=0;i<2;++i){
            while(left<=size&&nums[left]==i) ++left;
            right=left+1;
            while(right<=size){
                if(nums[right]==i){
                    swap(nums[left],nums[right]);
                    ++left;
                }
                ++right;
            }
        }
        return;
    }
};
