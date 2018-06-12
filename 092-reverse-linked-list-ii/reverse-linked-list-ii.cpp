// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note:&nbsp;1 &le; m &le; n &le; length of list.
//
// Example:
//
//
// Input: 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, m = 2, n = 4
// Output: 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr||m==n) return head;
        int count=1;
        auto th1=new ListNode(0);
        th1->next=head;
        auto th=new ListNode(0);
        auto p=head, pre=th1;
        while(count++<m) {
            pre=p;
            p=p->next;
        }    
        auto tail=p;
        while(count++<=n){
            pre->next=p->next;
            p->next=th->next;
            th->next=p;
            p=pre->next;
        }
        pre->next=p->next;
        p->next=th->next;
        th->next=p;
        p=pre->next;
        tail->next=p;
        pre->next=th->next;
        return th1->next;
    }
};
