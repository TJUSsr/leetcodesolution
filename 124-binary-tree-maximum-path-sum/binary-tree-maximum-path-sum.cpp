// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
//
// Example 2:
//
//
// Input: [-10,9,20,null,null,15,7]
//
// &nbsp;  -10
// &nbsp; &nbsp;/ \
// &nbsp; 9 &nbsp;20
// &nbsp; &nbsp; / &nbsp;\
// &nbsp; &nbsp;15 &nbsp; 7
//
// Output: 42
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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        DFS(root,res);
        return res;
    }
private:
    int DFS(TreeNode* root,int& res){
        if(root==nullptr) return 0;
        auto l=DFS(root->left,res);
        if(l<0) l=0;
        auto r=DFS(root->right,res);
        if(r<=0) r=0;
        if(root->val+l+r>res) res=root->val+l+r;
        return root->val+max(l,r);
    }
};
