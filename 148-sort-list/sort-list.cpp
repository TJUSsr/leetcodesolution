// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4-&gt;2-&gt;1-&gt;3
// Output: 1-&gt;2-&gt;3-&gt;4
//
//
// Example 2:
//
//
// Input: -1-&gt;5-&gt;3-&gt;4-&gt;0
// Output: -1-&gt;0-&gt;3-&gt;4-&gt;5
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
    ListNode *sortList(ListNode *head) {
        /*快排
        if(!head||!head->next)
            return head;
        Qsort(head,nullptr);
        return head;*/
        if(!head||!head->next)
            return head;
        auto mid=FindMid(head);
        auto right=mid->next;
        right=sortList(right);
        mid->next=nullptr;
        head=sortList(head);
        return merge(head,right);
    }
private:
    ListNode* FindMid(ListNode* head){
        if(!head)
            return head;
        auto fast=head;
        auto slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(p1==nullptr)
            return p2;
        if(p2==nullptr)
            return p1;
        auto head=p1;
        if(p1->val<p2->val){
            p1=p1->next;
        }
        else{
            head=p2;
            p2=p2->next;
        }
        auto ptr=head;
        while(p1!=nullptr&&p2!=nullptr){
            if(p1->val<p2->val){
                ptr->next=p1;
                ptr=ptr->next;
                p1=p1->next;
            }
            else{
                ptr->next=p2;
                ptr=ptr->next;
                p2=p2->next;
            }
        }
        if(p1==nullptr)
            ptr->next=p2;
        else if(p2==nullptr)
            ptr->next=p1;
        return head;
    }
    void Qsort(ListNode* head, ListNode* end){
        if(head!=end){
        	auto mid=Partition(head, end);
        	Qsort(head,mid);
        	Qsort(mid->next,end);
        }
    }
    ListNode* Partition(ListNode* head, ListNode* end){
        auto ptr=head->next;
        auto prePtr=head;
        int mark=head->val;
        while(ptr!=end){
            if(ptr->val<mark){
                prePtr=prePtr->next;
                if(prePtr!=ptr)
                    swap(prePtr,ptr);
            }
            ptr=ptr->next;
        }
        swap(head,prePtr);
        return prePtr;
    }
    void swap(ListNode* head, ListNode* end){
        int temp=head->val;
        head->val=end->val;
        end->val=temp;
        return;
    }
};
