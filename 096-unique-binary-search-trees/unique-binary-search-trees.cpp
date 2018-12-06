// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

vector<int> dp={1,1,2,5};

class Solution {
public:
    int numTrees(int n) {
        if(n>=dp.size()){
            for(int i=dp.size();i<=n;++i){
                int temp=0;
                for(int j=1;j<=i;++j){
                    temp+=(dp[i-j]*dp[j-1]);
                }
                dp.push_back(temp);
            }
        }
        return dp[n];
    }
};
