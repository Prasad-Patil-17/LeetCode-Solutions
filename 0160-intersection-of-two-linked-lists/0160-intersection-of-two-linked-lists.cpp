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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr && headB == nullptr) return NULL;
        
        ListNode* temp1 = headA;
        int list1_count = 0;

        ListNode* temp2 = headB;
        int list2_count = 0;

        //1. Count the length of the linked list;
        while(temp1 != nullptr){
            list1_count++;
            temp1 = temp1->next;
        }

        while(temp2 != nullptr){
            list2_count++;
            temp2 = temp2->next;
        }

        int req_count = abs(list1_count - list2_count);

        temp1 = headA;
        temp2 = headB;

        //2. make the temp pointer point to its required position//
        if(list1_count > list2_count){
            int temp_count = 1;

            while(temp1 != NULL && temp_count <= req_count){
                temp_count++;
                temp1 = temp1->next;
            }
        }
        else{
            int temp_count = 1;

            while(temp2 != NULL && temp_count <= req_count){
                temp_count++;
                temp2 = temp2->next;
            }
        }

        //2. After the above loop traverse using 2 pointers from start//
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1 == temp2) return temp1;

        return NULL;
    }
};