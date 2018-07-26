// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)
// Output: 7 -&gt; 0 -&gt; 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *node = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
      node = new ListNode(carry);            // init with carry from prev digits
      if (l1 != NULL) {                      // += l1.val, if any
        assert(l1->val >=0 && l1->val < 10); 
        node->val += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {                      // += l1.val, if any
        assert(l2->val >=0 && l2->val < 10);
        node->val += l2->val;
        l2 = l2->next;
      }
      if (node->val >= 10) {                 // handle carry
        carry = 1;
        node->val -= 10;
      }
      else {
        carry = 0;
      }
      if (head == NULL)                      // update head/tail
        head = node;
      if (tail != NULL)
        tail->next = node;
      tail = node;
    }
    if (carry) {
      node = new ListNode(carry);
      tail->next = node;
      tail = node;
    }      
    return head;
        
    }
};
