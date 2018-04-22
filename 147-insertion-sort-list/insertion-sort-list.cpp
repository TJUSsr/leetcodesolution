// Sort a linked list using insertion sort.
//
//
//
//
//
// A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
// With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
// &nbsp;
//
//
//
//
// Algorithm of Insertion Sort:
//
//
// 	Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
// 	At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// 	It repeats until no input elements remain.
//
//
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
