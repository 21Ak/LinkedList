/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Head node is not given
// Only the node to be deleted is given
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // substituting next node's value in the given node
        node->val = node->next->val;

        // now storing next to next node's address in current node's next
        node->next = node->next->next;
    }
};