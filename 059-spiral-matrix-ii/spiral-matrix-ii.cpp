// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int num=1;
        int left=0,right=n-1,up=0,down=n-1;
        while(left<=right&&up<=down){
            if(left<=right&&up<=down){
                for(int i=left;i<=right;++i)
                    res[up][i]=num++;
                ++up;
            }
            if(left<=right&&up<=down){
                for(int i=up;i<=down;++i)
                    res[i][right]=num++;
                --right;
            }
            if(left<=right&&up<=down){
                for(int i=right;i>=left;--i)
                    res[down][i]=num++;
                --down;
            }
            if(left<=right&&up<=down){
                for(int i=down;i>=up;--i)
                    res[i][left]=num++;
                ++left;
            }
        }
        return res;
    }
};
