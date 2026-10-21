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
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        
        //Using the concept of 3 pointers//
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;

        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        ListNode* reversed_head = previous;

        return reversed_head;
    }
};