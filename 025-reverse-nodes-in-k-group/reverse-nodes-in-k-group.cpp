// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1-&gt;2-&gt;3-&gt;4-&gt;5
//
// For k = 2, you should return: 2-&gt;1-&gt;4-&gt;3-&gt;5
//
// For k = 3, you should return: 3-&gt;2-&gt;1-&gt;4-&gt;5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list&#39;s nodes, only nodes itself may be changed.
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
    std:ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||k==1)
            return head;
        int num=0;
        auto cur=head;
        while(cur){
            cur=cur->next;
            ++num;
        }
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        auto pre=dummyhead;
        cur=head;
        while(num>=k){
            ListNode *newh=nullptr,*mark=cur;
            for(int i=0;i<k;++i){
                ListNode *temp=cur->next;
                cur->next=newh;
                newh=cur;
                cur=temp;
            }
            pre->next=newh;
            mark->next=cur;
            pre=mark;
            num-=k;
        }
        return dummyhead->next;
    }
};
