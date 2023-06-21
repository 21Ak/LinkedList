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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newList = new ListNode();
        newList->next = head;
        ListNode* fast = newList;
        ListNode* slow = newList;
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        // start moving slow pointer by a delay of n steps compared to fast
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;

        return newList->next;
    }
};