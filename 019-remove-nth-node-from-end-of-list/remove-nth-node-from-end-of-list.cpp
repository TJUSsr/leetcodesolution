// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        auto dummyhead=new ListNode(0);
        dummyhead->next=head;
        auto mark=dummyhead;
        for(int i=0;i<n;++i){
            mark=mark->next;
        }
        auto cur=dummyhead;
        auto temp=cur;
        while(mark){
            mark=mark->next;
            temp=cur;
            cur=cur->next;
        }
        temp->next=cur->next;
        return dummyhead->next;;
    }
};
