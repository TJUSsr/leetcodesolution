// Given a linked&nbsp;list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
//
// Input: 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, k = 2
// Output: 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
// Explanation:
// rotate 1 steps to the right: 5-&gt;1-&gt;2-&gt;3-&gt;4-&gt;NULL
// rotate 2 steps to the right: 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
//
//
// Example 2:
//
//
// Input: 0-&gt;1-&gt;2-&gt;NULL, k = 4
// Output: 2-&gt;0-&gt;1-&gt;NULL
// Explanation:
// rotate 1 steps to the right: 2-&gt;0-&gt;1-&gt;NULL
// rotate 2 steps to the right: 1-&gt;2-&gt;0-&gt;NULL
// rotate 3 steps to the right:&nbsp;0-&gt;1-&gt;2-&gt;NULL
// rotate 4 steps to the right:&nbsp;2-&gt;0-&gt;1-&gt;NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0) return head;
        bool overflow=false;
        auto mark=head;
        int size=0;
        for(int i=0;i<k;++i){
            mark=mark->next;
            ++size;
            if(mark==nullptr){
                overflow=true;
                break;
            }
        }
        if(overflow){
            k%=size;
            if(k==0) return head;
            mark=head;
            for(int i=0;i<k;++i){
                mark=mark->next;
                ++size;
                if(mark==nullptr){
                    overflow=true;
                    break;
                }
            }
        }
        auto p=head,temp=p,tempm=mark;
        while(mark){
            temp=p;
            tempm=mark;
            p=p->next;
            mark=mark->next;
        }
        temp->next=nullptr;
        tempm->next=head;
        return p;
    }
};
