// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res; 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                auto head=q.front();
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
                if(i==size-1) res.push_back(head->val);
                q.pop();
            }
        }
        return res;
    }
};
