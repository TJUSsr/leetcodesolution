// Given a binary tree
//
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
//
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
//
// 	You may only use constant extra space.
// 	Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//
//
// Example:
//
// Given the following binary tree,
//
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
//
//
// After calling your function, the tree should look like:
//
//
//      1 -&gt; NULL
//    /  \
//   2 -&gt; 3 -&gt; NULL
//  / \    \
// 4-&gt; 5 -&gt; 7 -&gt; NULL
//
//


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        TreeLinkNode* next,*p,*temp;
        while(root){
            p=root;next=nullptr;
            while(p){
                if(p->left&&p->right){
                    if(next==nullptr)
                        next=p->left;
                    p->left->next=p->right;
                    temp=p->next;
                    while(temp&&temp->left==nullptr&&temp->right==nullptr) temp=temp->next;
                    if(temp&&temp->left) p->right->next=temp->left;
                    else if(temp&&temp->right) p->right->next=temp->right;
                } 
                else if(p->left){
                    if(next==nullptr)
                        next=p->left;
                    temp=p->next;
                    while(temp&&temp->left==nullptr&&temp->right==nullptr) temp=temp->next;
                    if(temp&&temp->left) p->left->next=temp->left;
                    else if(temp&&temp->right) p->left->next=temp->right;
                }else if(p->right){
                    if(next==nullptr)
                        next=p->right;
                    temp=p->next;
                    while(temp&&temp->left==nullptr&&temp->right==nullptr) temp=temp->next;
                    if(temp&&temp->left) p->right->next=temp->left;
                    else if(temp&&temp->right) p->right->next=temp->right;
                }else{
                    temp=p->next;
                }
                p=temp;
            }
            root=next;
        }
    }
};
