// Given a binary tree, return the inorder traversal of its nodes&#39; values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        DFS(res,root);
        return res;
    }
private:
    void DFS(vector<int>& res, TreeNode* root){
        if(root->left)
            DFS(res,root->left);
        res.push_back(root->val);
        if(root->right)
            DFS(res,root->right);
        return;
    }
};
