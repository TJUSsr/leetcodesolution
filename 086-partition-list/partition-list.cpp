// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
//
// Input: head = 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;2, x = 3
// Output: 1-&gt;2-&gt;2-&gt;4-&gt;3-&gt;5
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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return head;
        auto s= new ListNode(0);
        auto b= new ListNode(0);
        auto p1=s,p2=b,p3=head;
        while(p3){
            if(p3->val<x){
                p1->next=p3;
                p1=p1->next;
            }else{
                p2->next=p3;
                p2=p2->next;
            }
            p3=p3->next;
        }
        p2->next=nullptr;
        p1->next=b->next;
        return s->next;
    }
};
