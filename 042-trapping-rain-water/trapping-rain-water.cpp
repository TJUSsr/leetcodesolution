// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        int res=0;
        vector<int> left(height.size(),0), right(height.size(),0);
        for(int i=0;i<height.size();++i){
            if(i==0) left[i]=height[i];
            else left[i]=max(left[i-1],height[i]);
        }
        for(int i=height.size()-1;i>=0;--i){
            if(i==height.size()-1) right[i]=height[i];
            else right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<height.size();++i){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};
