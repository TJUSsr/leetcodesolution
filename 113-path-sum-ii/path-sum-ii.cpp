// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
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
//  /  \    / \
// 7    2  5   1
//
//
// Return:
//
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tempres;
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        DFS(root,sum,0,tempres,res);
        return res;
    }
private:
    void DFS(TreeNode* root, int sum, int tempressum, vector<int> &tempres, vector<vector<int>> &res){
        tempres.push_back(root->val);
        tempressum+=root->val;
        if(root->left==nullptr&&root->right==nullptr){
            if(sum==tempressum)
                res.push_back(tempres);
        }
        else{
            if(root->left){
                DFS(root->left,sum,tempressum,tempres,res);    
            }
            if(root->right){
                DFS(root->right,sum,tempressum,tempres,res);    
            }    
        } 
        tempressum-=root->val;
        tempres.pop_back();
        return;
    }
};
