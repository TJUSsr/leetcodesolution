// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note:&nbsp;A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its minimum&nbsp;depth = 2.
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        /*
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0||r==0)
            return 1+l+r;
        else
        	return 1+min(l,r);*/
        int res=0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            ++res;
            int k=Q.size();
            for(int i=0;i<k;++i){
                if(Q.front()->left==nullptr&&Q.front()->right==nullptr)
                    return res;
                if(Q.front()->left)
                    Q.push(Q.front()->left);
                if(Q.front()->right)
                    Q.push(Q.front()->right);
                Q.pop();
            }
        }
        return res;
    }
};
