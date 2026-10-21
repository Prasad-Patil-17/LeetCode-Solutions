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
    ListNode* merge_lists(ListNode* head1,ListNode* head2){

        ListNode* temp_node = new ListNode(-1,nullptr);
        ListNode* helper = temp_node;

        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                helper->next = temp1;
                helper = helper->next;
                temp1 = temp1->next;
            }
            else{
                helper->next = temp2;
                helper = helper->next;
                temp2 = temp2->next;
            }
        }

        if(temp1 == NULL) helper->next = temp2;
        else helper->next = temp1;

        return temp_node->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        //1. Find the left middle of the linked list;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* left_list = head;
        ListNode* right_list = slow->next;
        slow->next = NULL;

        //2. Recursively call for the left unsorted list and right unsorted list;
        left_list = sortList(left_list);
        right_list = sortList(right_list);

        //3.Merge the 2 unsorted lists//
        ListNode* result = merge_lists(left_list,right_list);

        return result;
    }
};