// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        vector<int> tempres;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            tempres.clear();
            int size=q.size();
            for(int i=0;i<size;++i){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                tempres.push_back(q.front()->val);
                q.pop();
            }
            res.push_back(tempres);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
