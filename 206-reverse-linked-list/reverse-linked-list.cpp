// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
// Output: 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL
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
