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
    void deleteNode(ListNode* node) {

        // node->val = (node->next)->val;
        // ListNode* del_node = node->next;
        // node->next = del_node->next;
        // del_node->next = NULL;

        node->val = (node->next)->val;
        node->next = (node->next)->next;

        return;
    }
};