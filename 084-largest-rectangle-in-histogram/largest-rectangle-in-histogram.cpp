// Given n non-negative integers representing the histogram&#39;s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
// &nbsp;
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
// &nbsp;
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        
        for(int i = 0; i < height.size(); i++)
        {
            while(index.size() > 0 && height[index.back()] >= height[i])
            {
                int h = height[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }
        
        return ret;
    }
};
