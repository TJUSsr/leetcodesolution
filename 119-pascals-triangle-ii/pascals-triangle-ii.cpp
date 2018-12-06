// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

vector<vector<int>> res={{1},{1,1}};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tempres;
        for(int i=res.size();i<=rowIndex;++i){
            tempres.clear();
            tempres.push_back(1);
            for(int j=0;j<res[i-1].size()-1;++j){
                tempres.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            tempres.push_back(1);
            res.push_back(tempres);
        }
        return res[rowIndex];        
    }
};
