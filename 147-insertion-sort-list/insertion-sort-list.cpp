// Sort a linked list using insertion sort.


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
    ListNode *insertionSortList(ListNode *head) {
        if(!head||!head->next)
            return head;
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        auto prePtr=dummyhead;
        auto Ptr=head;
        /*while(Ptr){
            auto nextPtr=Ptr->next;
            auto mark=dummyhead;
            int temp=Ptr->val;
            while(mark->next->val<temp)
                mark=mark->next;
            if(mark->next==Ptr){
                prePtr=Ptr;
                Ptr=nextPtr;
            }
            else{
            	Ptr->next=mark->next;
            	mark->next=Ptr;
            	Ptr=nextPtr;
                prePtr->next=nextPtr;
            }
        }*/
        while(Ptr){
            if(Ptr->next&&Ptr->next->val<Ptr->val){
                while(prePtr->next->val<Ptr->next->val)
                    prePtr=prePtr->next;
                auto temp=prePtr->next;
                prePtr->next=Ptr->next;
                Ptr->next=Ptr->next->next;
                prePtr->next->next=temp;
                prePtr=dummyhead;
            }
            else
                Ptr=Ptr->next;
        }
        return dummyhead->next;
    }
};
