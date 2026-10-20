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
    ListNode* merge2lists(ListNode* head1,ListNode* head2){

        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        ListNode* temp_node = new ListNode(-1,nullptr);
        ListNode* helper = temp_node;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                helper->next = temp1;
                temp1 = temp1->next;
                helper = helper->next;
            }
            else{
                helper->next = temp2;
                temp2 = temp2->next;
                helper = helper->next;
            }
        }

        if(temp1 == NULL) helper->next = temp2;
        else helper->next = temp1;

        return temp_node->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        while(lists.size() > 1){

            ListNode* last = lists[lists.size()-1];
            lists.pop_back();

            ListNode* sec_last = lists[lists.size()-1];
            lists.pop_back();

            ListNode* merged_list = merge2lists(last,sec_last);

            lists.push_back(merged_list);
        }

        return lists[0];
    }
};