// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//
// But the following [1,2,2,null,3,null,3]  is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isM(root->left, root->right);
    }
    bool isM(TreeNode* le, TreeNode* ri){
        if(le==nullptr&&ri==nullptr) return true;
        else if(le==nullptr||ri==nullptr) return false;
        else if(le->val==ri->val) return isM(le->left,ri->right)&&isM(le->right,ri->left);
        else return false;
    }
    
};
