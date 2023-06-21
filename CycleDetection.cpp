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
    bool hasCycle(ListNode *head) {
        // // brute approach
        // // hashing all the nodes and then finding if any node repeats
        // // if any node repeats it means there exist a cycle
        // // TC O(N + 1) SC O(N)

        // if(head == NULL){
        //     return false;
        // }

        // unordered_set<ListNode*> st;

        // st.insert(head);
        // head = head->next;

        // while(head != NULL){
        //     if(st.find(head) != st.end()){
        //         return true;
        //     }
        //     st.insert(head);
        //     head = head->next;
        // }
        // return false;

        // // TC O(N+1) SC O(1)
        // // changing values of linkedlist to 1e9 and iterating till we get 1e9 again
        // // but this destroys the original list
        // if(head == NULL){
        //     return false;
        // }

        // while(head != NULL){
        //     head->val = 1e9;
        //     ListNode* temp = head->next;
        //     if(temp != NULL && temp->val == 1e9){
        //         return true;
        //     }
        //     head = head->next;
        // }
        // return false;

        // Slow and fast pointer approach
        // move fast pointer 2 nodes and slow pointer 1 node untill fast pointer is not null
        // if slow == fast => cycle exist

        if(head == NULL){
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};