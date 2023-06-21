/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* newList = new ListNode();
        ListNode* ptr = newList;
        int carry = 0;

        // adding each node's value while iterating over both the linkedlists
        // storing the generated linkedlist into a new linkedlist
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            ptr->next = node;
            ptr = ptr->next;
        }
        return newList->next;
    }
};