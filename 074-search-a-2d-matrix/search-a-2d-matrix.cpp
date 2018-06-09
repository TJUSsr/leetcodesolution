// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int h=matrix.size(),w=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[h-1][w-1]) return false;
        int left=0,right=h*w-1;
        while(left<=right){
            int mid=left+((right-left)>>1);
            auto sm=IndexToxy(mid,h,w);
            if(matrix[sm.first][sm.second]==target) return true;
            else if(matrix[sm.first][sm.second]<target) left=mid+1;
            else if(matrix[sm.first][sm.second]>target) right=mid-1;
        }
        return false;
    }
private:
    pair<int,int> IndexToxy(const int& index, const int& h, const int& w){
        int x=index/w;
        int y=index-x*w;
        return make_pair(x,y);
    }
};
