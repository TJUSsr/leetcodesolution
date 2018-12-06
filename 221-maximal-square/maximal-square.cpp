// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
//
// Input: 
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        int wid=matrix.size(),len=matrix[0].size();
        vector<int> l(len,0);
        vector<int> r(len,len);
        vector<int> h(len,0);
        int res=0,tempres=0;
        for(int i=0;i<wid;++i){
            int curleft=0,curright=len;
            for(int j=0;j<len;++j){
                if(matrix[i][j]=='1'){
                    ++h[j];
                    l[j]=max(curleft,l[j]);
                }else{
                    h[j]=0;
                    curleft=j+1;
                    l[j]=0;
                }
            }
            for(int j=len-1;j>=0;--j){
                if(matrix[i][j]=='1'){
                    r[j]=min(r[j],curright);
                }else{
                    curright=j;
                    r[j]=len;
                }
            }
            for(int j=0;j<len;++j){
                tempres=min(h[j],r[j]-l[j])*min(h[j],r[j]-l[j]);
                if(tempres>res)
                    res=tempres;
            }
        }
        return res;
    }
};
