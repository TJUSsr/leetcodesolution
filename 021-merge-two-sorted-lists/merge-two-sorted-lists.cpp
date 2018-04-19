// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummyhead=new ListNode(0);
        auto cur=dummyhead;
        while(l1&&l2){
            if(l1->val<=l2->val){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        cur->next=l1?l1:l2;
        return dummyhead->next;
    }
};
