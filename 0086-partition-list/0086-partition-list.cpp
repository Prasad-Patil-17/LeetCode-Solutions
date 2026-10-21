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
    ListNode* partition(ListNode* head, int x) {

        if(head == nullptr || head->next == nullptr) return head;
        
        //1. Maintain low and high nodes.
        ListNode* low_node = new ListNode(-1,nullptr);
        ListNode* low = low_node;

        ListNode* high_node = new ListNode(-1,nullptr);
        ListNode* high = high_node;

        //2. Connect the node as per requirements//
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                low->next = temp;
                low = temp;
            }
            else{
                high->next = temp;
                high = temp;
            }
            temp = temp->next;
        }

        //2. connect both low and high nodes.
        low->next = high_node->next;
        high->next = NULL;

        return low_node->next;
    }
};