// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int w=matrix.size(),l=matrix[0].size();
        vector<int> left(l,0);
        vector<int> right(l,l);
        vector<int> height(l,0);
        int res=0,tempres=0;
        for(int i=0;i<w;++i){
            int curleft=0,curright=l;
            for(int j=0;j<l;++j){
                if(matrix[i][j]=='1'){
                    ++height[j];
                    left[j]=max(curleft,left[j]);
                }else{
                    height[j]=0;
                    left[j]=0;
                    curleft=j+1;
                } 
            }
            for(int j=l-1;j>=0;--j){
                if(matrix[i][j]=='1'){
                   right[j]=min(curright,right[j]);
                }else{
                    right[j]=l;
                    curright=j;
                }
                tempres=(right[j]-left[j])*height[j];
                res=max(res,tempres);
            }
        }
        return res;
    }
};
