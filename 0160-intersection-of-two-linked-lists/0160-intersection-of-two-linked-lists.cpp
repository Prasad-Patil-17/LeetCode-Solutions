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
        
        if(headA == NULL && headB == NULL) return NULL;
        
        vector<ListNode*> list_1;
        list_1.push_back(headA);

        vector<ListNode*> list_2;
        list_2.push_back(headB);


        ListNode* temp1 = headA->next;
        while(temp1 != NULL){
            list_1.push_back(temp1);
            temp1 = temp1->next;
        }

        ListNode* temp2 = headB->next;
        while(temp2 != NULL){
            list_2.push_back(temp2);
            temp2 = temp2->next;
        }

        for(int i=0;i<list_1.size();i++){

            ListNode* current_adress = list_1[i];

            for(int j=0;j<list_2.size();j++){
                if(current_adress == list_2[j]) return current_adress;
            }
        }

        return NULL;
    }
};