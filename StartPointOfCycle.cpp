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
    ListNode *detectCycle(ListNode *head) {

        // // This apporach modifies the given linkedlist
        // if(head == NULL || head->next == NULL) return NULL;
        // while(head != NULL){
        //     head->val = 1e6;
        //     ListNode *temp = head->next;
        //     if(temp != NULL && temp->val == 1e6){
        //         return temp;
        //     }
        //     head = head->next;
        // }

        // return NULL;

        // moving fast and slow pointers till they collide
        // after that moving head pointer and slow pointer by 1 steps till they collide
        // collision point of head and slow pointer will be the starting point of cycle in Linkedlist

        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        bool flag = false;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }

        if(flag == false){
            return NULL;
        }

        while(head != slow){
            head = head->next;
            slow = slow->next;
        }

        return head;
    }
};