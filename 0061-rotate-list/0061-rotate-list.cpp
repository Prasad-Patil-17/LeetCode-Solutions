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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return NULL;

        //1. Calculate the length and mark the tail
        ListNode* temp = head;
        ListNode* tail = NULL;
        int length = 0;

        while(temp != NULL){
            if(temp->next == NULL) tail = temp;
            length++;
            temp = temp->next;
        }

        temp = head;

        if(k == length) return head;
        else if(k > length) k = k % length;

        //2. Make temp point to its correct position//
        int count = 1;
        while(temp != NULL && count < (length - k)){
            count++;
            temp = temp->next;
        }

        //3. Adjust the pointers to rotate the list//
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        tail = temp;

        return head;
    }
};