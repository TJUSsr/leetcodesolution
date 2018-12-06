// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n<=0) return res;
        res=DFS(1,n);
        return res;
    }
private:
    vector<TreeNode*> DFS(int left, int right){
        vector<TreeNode*> res;
        if(left>right){
            res.push_back(nullptr);
        }
        else if(left==right){
            auto p=new TreeNode(left);
            res.push_back(p);
        }else{
            for(int i=left;i<=right;++i){
                auto l=DFS(left,i-1);
                auto r=DFS(i+1,right);
                for(int n1=0;n1<l.size();++n1){
                    for(int n2=0;n2<r.size();++n2){
                        auto p=new TreeNode(i);
                        p->left=l[n1];
                        p->right=r[n2];
                        res.push_back(p);
                    }
                }
            }
        }
        return res;
    }
};
