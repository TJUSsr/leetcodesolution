// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        auto dh=new ListNode(0),p=head;
        while(p){
            auto temp=dh->next;
            dh->next=p;
            p=p->next;
            dh->next->next=temp;
        }
        return dh->next;
    }
};
