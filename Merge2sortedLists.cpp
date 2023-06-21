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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // // External space solution
        // // Create a new linkedlist
        // // traverse both given lists and compare their elements, store smaller elements before the larger ones
        // ListNode* newHead = new ListNode(0);
        // ListNode* cur = newHead;

        // while(list1 != NULL && list2 != NULL){
        //     if(list1->val <= list2->val){
        //         cur->next = list1;
        //         list1 = list1->next;
        //     }
        //     else{
        //         cur->next = list2;
        //         list2 = list2->next;
        //     }
        //     cur = cur->next;
        // }

        // if(list1 != NULL){
        //     cur->next = list1;
        // }
        // if(list2 != NULL){
        //     cur->next = list2;
        // }

        // newHead = newHead->next;
        // return newHead;

        // IN Place Solution
        // we form new linkedlist without using external space

         //If one list is null simply return the other
        if(list1==0) return list2;
        if(list2==0) return list1;
        //Choose the smaller one initilly
        if(list1->val > list2->val) swap(list1,list2);
        ListNode* res = list1;
        //Until both the lists are ended
        while(list1 != NULL && list2 !=NULL){
            ListNode* temp = NULL;
            //Keep adding l1 while l1 is smaller
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            //As l2 is now the smaller one
            temp->next = list2;
            //Swap l1 and l2 for next iteration
            swap(list1,list2);
        }
        return res;

    }
};