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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Using slow and fast pointers technique//
        ListNode* slow = head;
        ListNode* fast = head;

        if(n == 1 && head->next == NULL){
            head = head->next;
            return head;
        }

        //Make fast point to (n+1)th node;
        for(int i=1;i<=n+1;i++){
            if(fast == NULL) return head->next;
            fast = fast->next;
        }

        //Move slow and fast with the same speed//
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* del_node = slow->next;

        slow->next = del_node->next;
        del_node->next = NULL;

        delete del_node;

        return head;
    }
};