// Write a program to find the node at which the intersection of two singly linked lists begins.
//
// For example, the following two linked lists: 
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
//
// begin to intersect at node c1.
//
// Notes:
//
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns. 
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
//
//
//
// Credits:Special thanks to @stellari for adding this problem and creating all test cases.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr) return nullptr;
        if(headA==headB) return headA;
        auto p1=headA; while(p1->next) p1=p1->next;
        auto p2=headB; while(p2->next) p2=p2->next;
        if(p1!=p2) return nullptr;
        p1=headA->next;
        if(p1==nullptr) return headA;
        p2=headA->next->next;
        if(p2==nullptr) return p1;
        while(p1!=p2){
            if(p1->next==nullptr) p1=headB;
            else p1=p1->next;
            if(p2->next==nullptr) p2=headB->next;
            else if(p2->next->next==nullptr) p2=headB;
            else p2=p2->next->next;
        }
        p1=headA;
        while(p1!=p2){
            if(p1->next==nullptr) p1=headB;
            else p1=p1->next;
            if(p2->next==nullptr) p2=headB;
            else p2=p2->next;
        }
        return p1;
    }
};
