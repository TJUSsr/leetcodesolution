// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
// return its depth = 3.
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            ++res;
            for(int i=0;i<size;++i){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return res;
    }
};
