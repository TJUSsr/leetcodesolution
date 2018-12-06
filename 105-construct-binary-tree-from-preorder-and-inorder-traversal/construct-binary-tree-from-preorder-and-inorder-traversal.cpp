// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2){
        if(l1>=r1||l2>=r2) return nullptr;
        auto p=new TreeNode(preorder[l1]);
        auto f=find(inorder.begin()+l2,inorder.begin()+r2,preorder[l1]);
        auto dis=f-inorder.begin()-l2;
        p->left=buildTree(preorder,l1+1,l1+1+dis,inorder,l2,l2+dis);
        p->right=buildTree(preorder,l1+1+dis,r1,inorder,l2+dis+1,r2);
        return p;
    }
};
