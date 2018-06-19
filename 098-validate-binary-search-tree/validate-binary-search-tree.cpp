// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than the node&#39;s key.
// 	The right subtree of a node contains only nodes with keys greater than the node&#39;s key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
// Example 1:
//
//
// Input:
//     2
//    / \
//   1   3
// Output: true
//
//
// Example 2:
//
//
//     5
//    / \
//   1   4
// &nbsp;    / \
// &nbsp;   3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node&#39;s value
// &nbsp;            is 5 but its right child&#39;s value is 4.
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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=nullptr;
        return DFS(root,pre);
    }
private:
    bool DFS(TreeNode* root, TreeNode* &pre){
        if(root==nullptr) return true;
        if(!DFS(root->left,pre)) return false;
        if(pre!=nullptr&&pre->val>=root->val) return false;
        pre=root;
        return(DFS(root->right,pre));
    }
};
