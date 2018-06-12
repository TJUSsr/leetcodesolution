// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1-&gt;2-&gt;6-&gt;3-&gt;4-&gt;5-&gt;6, val = 6
// Output: 1-&gt;2-&gt;3-&gt;4-&gt;5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        auto dh=new ListNode(0),p=head,p1=dh;
        while(p){
            if(p->val==val){
                p=p->next;
                continue;
            }
            p1->next=p;
            p1=p;
            p=p->next;
        }
        p1->next=nullptr;
        return dh->next;
    }
};
