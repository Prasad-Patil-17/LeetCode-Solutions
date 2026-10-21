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
    ListNode* reverse_list(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;

        // Using the concept of 3 pointers
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        ListNode* reversed_head = previous;

        return reversed_head;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) return true;
        
        //1. Calculate the length of the linked list.
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        if(length % 2 == 0){
            ListNode* slow = head;
            ListNode* fast = head;

            //reach till the middle of the node//
            while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* next_node = slow->next;
            slow->next = NULL;

            ListNode* rev_head = reverse_list(next_node);
            ListNode* temp1 = head;
            ListNode* temp2 = rev_head;

            while(temp1 != NULL && temp2 != NULL){
                if(temp1->val != temp2->val) return false;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else{
            ListNode* slow = head;
            ListNode* fast = head;

            //reach till the middle of the node//
            ListNode* prev_node = NULL;

            while(fast != NULL && fast->next != NULL){
                prev_node = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* next_node = prev_node->next->next;
            prev_node->next = NULL;

            ListNode* rev_head = reverse_list(next_node);
            ListNode* temp1 = head;
            ListNode* temp2 = rev_head;

            while(temp1 != NULL && temp2 != NULL){
                if(temp1->val != temp2->val) return false;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return true;
    }
};