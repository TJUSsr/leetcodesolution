// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int h=matrix.size(),w=matrix[0].size();
        int left=0,right=w-1,up=0,down=h-1;
        while(left<=right&&up<=down){
            if(left<=right&&up<=down){
                for(int i=left;i<=right;++i)
                    res.push_back(matrix[up][i]);
                ++up;
            }
            if(left<=right&&up<=down){
                for(int i=up;i<=down;++i)
                    res.push_back(matrix[i][right]);
                --right;
            }
            if(left<=right&&up<=down){
                for(int i=right;i>=left;--i)
                    res.push_back(matrix[down][i]);
                --down;
            }
            if(left<=right&&up<=down){
                for(int i=down;i>=up;--i)
                    res.push_back(matrix[i][left]);
                ++left;
            }
        }
    return res;
    }
};
