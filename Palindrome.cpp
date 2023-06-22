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
    //Reverse the linked List
    ListNode* reverseList(ListNode* head) {
        ListNode * newHead = NULL ;
        while(head!=NULL)
        {
            ListNode *next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
        }
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        //Edge case
        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // mid of linked list
        while(fast -> next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //next to/ mid, reverse the remaining LL
        slow -> next = reverseList(slow->next);
        slow = slow->next ;  //starting node of revesered LL

        while(slow != NULL) //compare the head of LL with reversed LL
        {
            if(head ->val != slow ->val)
            {
                return false;
            }

            head = head->next;
            slow = slow->next;
        }

        return true;


        // Brute Force Approach

        // vector<int> v ;
        // ListNode *temp = head ;
        // while(temp!=NULL){
        //     v.push_back(temp->val) ;
        //     temp = temp->next ;
        // }
        // int i , n = v.size(),j ;
        // i = 0 , j = n-1 ;
        // while(i<j){
        //     if(v[i]!=v[j]){
        //         return false ;
        //     }
        //     else{
        //         i++ ;
        //         j-- ;
        //     }
        // }
        // return true ;

    }
};