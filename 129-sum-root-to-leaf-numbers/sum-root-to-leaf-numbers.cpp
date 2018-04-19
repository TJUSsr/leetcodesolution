// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
// An example is the root-to-leaf path 1-&gt;2-&gt;3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// For example,
//
//
//     1
//    / \
//   2   3
//
//
// &nbsp;
//
// The root-to-leaf path 1-&gt;2 represents the number 12.
// The root-to-leaf path 1-&gt;3 represents the number 13.
//
// Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        return PrivateSum(root,0);
    }
private:
    int PrivateSum(TreeNode* root, int sum){
        sum=10*sum+root->val;
        if(!root->left&&!root->right)
            return sum;
        int left=0,right=0;
        if(root->left)
            left=PrivateSum(root->left,sum);
        if(root->right)
            right=PrivateSum(root->right,sum);
        return left+right;
    }
};
