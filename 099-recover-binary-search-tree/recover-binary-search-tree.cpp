// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
//
// Input: [1,3,null,null,2]
//
// &nbsp;  1
// &nbsp; /
// &nbsp;3
// &nbsp; \
// &nbsp;  2
//
// Output: [3,1,null,null,2]
//
// &nbsp;  3
// &nbsp; /
// &nbsp;1
// &nbsp; \
// &nbsp;  2
//
//
// Example 2:
//
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
// &nbsp;  /
// &nbsp; 2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
// &nbsp;  /
//  &nbsp;3
//
//
// Follow up:
//
//
// 	A solution using O(n) space is pretty straight forward.
// 	Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        vector<int> num;
        ZX(num,root);
        sort(num.begin(),num.end());
        int i=0;
        ZX_1(num,root,i);
    }
private:
    void ZX(vector<int>& num, TreeNode* root){
        if(root==nullptr)
            return;
        ZX(num,root->left);
        num.push_back(root->val);
        ZX(num,root->right);
        return;
    }
    void ZX_1(const vector<int>& num, TreeNode* root,int& i){
        if(root==nullptr)
            return;
        ZX_1(num,root->left,i);
        root->val=num[i];
        ++i;
        ZX_1(num,root->right,i);
        return;
    }
};
