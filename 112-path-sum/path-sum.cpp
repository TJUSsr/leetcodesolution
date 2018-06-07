// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
// Note:&nbsp;A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
//
//
// return true, as there exist a root-to-leaf path 5-&gt;4-&gt;11-&gt;2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        int temp=0;
        return DFS(root,sum,temp);
    }
private:
    bool DFS(TreeNode* root, int sum, int temp){
        temp+=root->val;
        if(root->left==nullptr&&root->right==nullptr)
            if(temp==sum) return true;
            else return false;
        bool res=false;
        if(root->left)
            res=res||DFS(root->left,sum,temp);
        if(root->right)
            res=res||DFS(root->right,sum,temp);
        return res;
    }
};
