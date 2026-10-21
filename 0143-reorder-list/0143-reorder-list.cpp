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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

    void reorderList(ListNode* head){

        if(head == nullptr || head->next == nullptr) return;

        //1. Find the left middle of the linked list//
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. divide the list into 2 halves//
        ListNode* next_node = slow->next;
        slow->next = NULL;

        //3. reverse the second half of the list//
        ListNode* rev_head = reverse_list(next_node);

        //4. Create a temp_node and connect based on the requirements//
        ListNode* list1 = head;
        ListNode* list2 = rev_head;

        ListNode* temp_node = new ListNode(-1,nullptr);
        ListNode* temp = temp_node;

        while(list1 != nullptr && list2 != nullptr){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;

            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        if(list1 == nullptr){
            temp->next = list2;
        }
        else{
            temp->next = list1;
        }

        head = temp_node->next;
        delete temp_node;

        return;
    }
};