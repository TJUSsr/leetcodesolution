// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
// &nbsp;            (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int min_n=INT_MAX,max_n=INT_MIN,size=nums.size();
        for(const auto &n:nums){
            if(n<min_n) min_n=n;
            if(n>max_n) max_n=n;
        }
        if(min_n==max_n) return 0;
        int diff=max_n-min_n;
        int length_bucket=max(diff/(size-1),1);
        int m=diff/length_bucket+1;
        vector<vector<int>> buc(m);
        for(const auto&n:nums){
            int index=(n-min_n)/length_bucket;
            if(buc[index].empty()){
                buc[index].push_back(n);
                buc[index].push_back(n);
            }else{
                if(n<buc[index][0]) buc[index][0]=n;
                if(n>buc[index][1]) buc[index][1]=n;
            }
        }
        int res=INT_MIN,premax=buc[0][0];
        for(const auto& pair:buc){
            if(pair.empty()) continue;
            if(pair[1]-pair[0]>res) res=pair[1]-pair[0];
            if(pair[0]-premax>res) res=pair[0]-premax;
            premax=pair[1];
        }
        return res;
    }
};
