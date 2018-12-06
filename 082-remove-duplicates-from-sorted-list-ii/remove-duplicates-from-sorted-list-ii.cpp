// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// Example 1:
//
//
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
//
// Example 2:
//
//
// Input: 1->1->1->2->3
// Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyhead=new ListNode(0);
        auto p=dummyhead,p1=head;
        while(p1){
            int count=1;
            while(p1->next&&p1->val==p1->next->val) {p1=p1->next;++count;};
            if(count==1){
                p->next=p1;
                p=p->next;
            }
            p1=p1->next;
        }
        p->next=nullptr;
        return dummyhead->next;
    }
};
