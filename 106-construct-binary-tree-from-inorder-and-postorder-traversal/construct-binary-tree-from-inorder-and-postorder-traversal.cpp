// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder =&nbsp;[9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
    TreeNode* buildTree(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2){
        if(l1>=r1||l2>=r2) return nullptr;
        auto p=new TreeNode(postorder[r2-1]);
        auto f=find(inorder.begin()+l1,inorder.begin()+r1,postorder[r2-1]);
        auto dis=f-inorder.begin()-l1;
        p->left=buildTree(inorder,l1,l1+dis,postorder,l2,l2+dis);
        p->right=buildTree(inorder,l1+dis+1,r1,postorder,l2+dis,r2-1);
        return p;
    }
};
