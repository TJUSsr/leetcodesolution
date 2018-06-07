// Given a non-negative integer&nbsp;numRows, generate the first numRows of Pascal&#39;s triangle.
//
//
// In Pascal&#39;s triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

vector<vector<int>> res={{0},{1}};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tempres;
        for(int i=res.size();i<=numRows;++i){
            tempres.clear();
            tempres.push_back(1);
            for(int j=0;j<res[i-1].size()-1;++j){
                tempres.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            tempres.push_back(1);
            res.push_back(tempres);
        }
        return vector<vector<int>>(res.begin()+1,res.begin()+numRows+1);
    }
};
