// Given a binary tree, return the preorder traversal of its nodes&#39; values.
//
// Example:
//
//
// Input:&nbsp;[1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output:&nbsp;[1,2,3]
//
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root,res);
        return res;
    }
private:
    vector<int> res;
    void preorder(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
        return;
    }
};
