// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
//
//
// Input: 1-&gt;1-&gt;2
// Output: 1-&gt;2
//
//
// Example 2:
//
//
// Input: 1-&gt;1-&gt;2-&gt;3-&gt;3
// Output: 1-&gt;2-&gt;3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        auto p=head;
        auto pre=p;
        while(p){
            pre=p;
            while(p->next&&p->val==p->next->val) p=p->next;
            if(pre!=p){
                p=p->next;
                pre->next=p;
            }else{
                p=p->next;
            }
        }
        return head;
    }
};
