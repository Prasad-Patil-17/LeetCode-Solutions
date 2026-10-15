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
    ListNode* middleNode(ListNode* head) {


        //calculate the count of the linked list//
        ListNode* temp = head;
        int node_count = 0;
        while(temp != NULL){
            node_count++;
            temp = temp->next;
        }

        if(node_count == 1) return head;
        
        if(node_count % 2 == 0){

            int middle = node_count/2;
            int count = 1;

            temp = head;
            while(temp != NULL && count < middle){
                count++;
                temp = temp->next;
            }

            ListNode* first_node = temp;
            ListNode* second_node = temp->next;

            return second_node;
        }
        else{ //node_count is odd
            int middle = node_count/2;

            temp = head;
            int count = 1;

            while(temp != NULL && count < middle){
                count++;
                temp = temp->next;
            }

            ListNode* individual_node = temp->next;
            return individual_node;
        }
    }
};