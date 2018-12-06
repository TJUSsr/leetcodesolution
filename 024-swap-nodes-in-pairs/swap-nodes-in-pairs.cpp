// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Note:
//
//
// 	Your algorithm should use only constant extra space.
// 	You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        auto newh=head->next;
        auto cur=head;
        auto nex=head->next;
        ListNode* pre=nullptr;
        while(cur&&nex){
            auto temp=nex->next;
            if(pre)
                pre->next=nex;
            cur->next=temp;
            nex->next=cur;
            pre=cur;
            cur=temp;
            if(cur)
                nex=cur->next;
            else
                nex=nullptr;
        }
        return newh;
    }
};
