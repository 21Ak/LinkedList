/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int difference(ListNode *headA, ListNode *headB){
        int l1 = 0, l2 = 0;
        while(headA != NULL){
            ++l1;
            headA = headA->next;
        }
        while(headB != NULL){
            ++l2;
            headB = headB->next;
        }
        
        return (l1 - l2);
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // // storing all nodes of list A in a set and then finding for common node
        // // SC O(n+m) TC O(n or m);
        // unordered_set<ListNode*> st;
        // while(headA != NULL){
        //     st.insert(headA);
        //     headA = headA->next;
        // }

        // while(headB != NULL){
        //     if(st.find(headB) != st.end()){
        //         return headB;
        //     }
        //     headB = headB->next;
        // }

        // return NULL;

        // Get difference btw lengths of both linkedlists 
        // then move the pointer of larger linkedlist by length differnce 
        // then move both pointers together
        // TC O(n + m) SC O(1)

        int diff = difference(headA, headB);
        if(diff < 0){
            while(diff++ != 0){
                headB = headB->next;
            }
        }
        else{
            while(diff-- != 0){
                headA = headA->next;
            }
        }

        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};