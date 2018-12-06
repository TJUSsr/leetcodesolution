// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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

struct compare{
    bool operator()(const ListNode* a,const ListNode* b){
        return a->val>b->val;
    }
};
struct ListNodeCmp {	
	bool operator () (const ListNode*n1, const ListNode*n2) {
		return n1->val > n2->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,compare > heap;
        ListNode* cur;
        for(int i=0;i<lists.size();++i){
            cur=lists[i];
            while(cur){
                heap.push(cur);
                cur=cur->next;
            }
        }
        auto dummyhead=new ListNode(0);
        cur=dummyhead;
        while(!heap.empty()){
            cur->next=heap.top();
            heap.top()->next=nullptr;
            cur=cur->next;
            heap.pop();
        }
        return dummyhead->next;
    }
};
