// Given an array of size n, find the majority element. The majority element is the element that appears more than &lfloor; n/2 &rfloor; times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: 3
//
// Example 2:
//
//
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int* res=nullptr;
        int count=0;
        for(const auto&i:nums){
            if(count==0)
                res=&i;
            count+=(*res==i)?1:-1;
        }
        return *res;
    }
};
