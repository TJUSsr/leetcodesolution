// Given a binary tree, return the postorder traversal of its nodes&#39; values.
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
// Output:&nbsp;[3,2,1]
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
    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root, res);
        return res;
    }
private:
    vector<int> res;
    void postorder(TreeNode* root, vector<int>& res){
        if(root==nullptr)
            return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
        return;
    }
};
