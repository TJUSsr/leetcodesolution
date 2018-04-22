// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,left=0,right=height.size()-1,temp;
        while(left<right){
            if(height[left]>height[right])
                temp=height[right]*(right-left);
            else
                temp=height[left]*(right-left);
            res=res>temp?res:temp;
            if(height[left]>height[right]) --right;
            else ++left;
        }
        return res;
    }
};
