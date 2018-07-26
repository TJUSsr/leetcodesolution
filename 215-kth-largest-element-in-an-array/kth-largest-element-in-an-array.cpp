// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
//
// Example 2:
//
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note: 
// You may assume k is always valid, 1 &le; k &le; array&#39;s length.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1,target=nums.size()-k;
        while(left<=right){
            int index=partation(nums,left,right);
            if(index==target)
                break;
            else if(index<target)
                left=index+1;
            else
                right=index-1;
        }
        return nums[nums.size()-k];
    }
private:
    int partation(vector<int>& nums,int left,int right){
        int remark=nums[right];
        int j=left-1;
        for(int i=left;i<=right;++i){
            if(nums[i]<=remark){
                ++j;
                if(i!=j)
                    swap(nums[i],nums[j]);
            }
        }
        return j;
    }
};
