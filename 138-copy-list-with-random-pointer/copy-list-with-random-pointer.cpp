//
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//
//
// Return a deep copy of the list.
//


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        RandomListNode* Ptr=head;
        while(Ptr){
            RandomListNode* newPtr=new RandomListNode(Ptr->label);
            newPtr->next=Ptr->next;
            Ptr->next=newPtr;
            Ptr=newPtr->next;
        }
        Ptr=head;
        while(Ptr){
            Ptr->next->random=Ptr->random?Ptr->random->next:nullptr;
            Ptr=Ptr->next->next;
        }
        Ptr=head;
        auto newhead=head->next;
        RandomListNode* temp;
        while(Ptr){
            temp=Ptr->next->next;
            Ptr->next->next=temp?temp->next:nullptr;
            Ptr->next=temp;
            Ptr=temp;
        }
        return newhead;
    }
};
