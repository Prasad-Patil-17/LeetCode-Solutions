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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //find the length of the linked list//
        int length = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            length++;
            temp = temp->next;
        }

        //Break the lists into k lists//
        vector<ListNode*> list_parts;

        int size = length/k;
        int rem = length % k;
        temp = head;

        while(temp != nullptr){
            ListNode* temp_node = new ListNode(-1,nullptr);
            ListNode* helper = temp_node;

            int s = size;
            if(rem > 0) s++;
            rem--;

            for(int i=1;i<=s;i++){
                helper->next = temp;
                temp = temp->next;
                helper = helper->next;
            }
            helper->next = nullptr;
            list_parts.push_back(temp_node->next);
        }

        if(list_parts.size() < k){
            int extra = k - list_parts.size();
            for(int i=1;i<=extra;i++){
                list_parts.push_back(nullptr);
            }
        }

        return list_parts;
    }
};