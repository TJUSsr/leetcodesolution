// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res; 
        bool f=true;
        list<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();
            if(f){
                for(int i=0;i<size;++i){
                    temp.push_back(q.front()->val);
                    if(q.front()->left) q.push_back(q.front()->left);
                    if(q.front()->right) q.push_back(q.front()->right);
                    q.pop_front();
                }
            }else{
                for(int i=0;i<size;++i){
                    temp.push_back(q.back()->val);
                    if(q.back()->right) q.push_front(q.back()->right);
                    if(q.back()->left) q.push_front(q.back()->left);
                    q.pop_back();
                }
            }
            f=!f;
            res.push_back(temp);
        }
        return res;
    }
};
