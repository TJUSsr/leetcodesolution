// Given a singly linked list L: L0&rarr;L1&rarr;&hellip;&rarr;Ln-1&rarr;Ln,
// reorder it to: L0&rarr;Ln&rarr;L1&rarr;Ln-1&rarr;L2&rarr;Ln-2&rarr;&hellip;
//
// You may not modify the values in the list&#39;s nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1-&gt;2-&gt;3-&gt;4, reorder it to 1-&gt;4-&gt;2-&gt;3.
//
// Example 2:
//
//
// Given 1-&gt;2-&gt;3-&gt;4-&gt;5, reorder it to 1-&gt;5-&gt;2-&gt;4-&gt;3.
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
class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head||!head->next)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        auto end=reorder(slow->next);
        slow->next=nullptr;
        auto ptr=head;
        auto p1=head->next;
        auto p2=end;
        bool p1_turn=false;
        while(p1&&p2){
            if(p1_turn){
                ptr->next=p1;
                ptr=ptr->next;
                p1=p1->next;
                p1_turn=false;
            }
            else{
                ptr->next=p2;
                ptr=ptr->next;
                p2=p2->next;
                p1_turn=true;
            }
        }
        if(p1) ptr->next=p1;
        if(p2) ptr->next=p2;
        return;
    }
private:
    ListNode* reorder(ListNode *head){
        if(!head||!head->next)
            return head;
        auto temp=head->next;
        head->next=nullptr;
        while(temp){
            auto nexttemp=temp->next;
            temp->next=head;
            head=temp;
            temp=nexttemp;
        }
        return head;
    }
};
