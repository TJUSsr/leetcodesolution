// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//
//
// Example 2:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
//
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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        list<TreeNode*> q;
        unordered_set<int> s;
        int temp;
        q.push_back(root);
        while(!q.empty()){
            temp=k-q.front()->val;
            if(s.count(temp)==1) return true;
            s.insert(q.front()->val);
            if(q.front()->left) q.push_back(q.front()->left);
            if(q.front()->right) q.push_back(q.front()->right);
            q.pop_front();
        }
        return false;
    }
};
