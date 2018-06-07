// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int size=nums.size()-1;
        return Partation(nums,0,size);
    }
private:
    TreeNode* Partation(const vector<int>& nums, int left, int right){
        if(left>right) return nullptr;
        if(left==right) return new TreeNode(nums[left]);
        int mid=left+((right-left+1)>>1);
        auto root=new TreeNode(nums[mid]);
        root->left=Partation(nums,left,mid-1);
        root->right=Partation(nums,mid+1,right);
        return root;
    }
};
