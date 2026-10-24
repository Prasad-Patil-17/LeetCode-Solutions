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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        //1. first find the maximum distance//
        int idx = 1;

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nxt = curr->next;

        if(nxt == nullptr) return {-1,-1};

        int first_idx = -1;
        int sec_idx = -1;

        while(nxt){
            if(curr->val > prev->val && curr->val > nxt->val || curr->val < prev->val && curr->val < nxt->val){
                if(first_idx == -1) first_idx = idx;
                else sec_idx = idx;
            }
            
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;

            idx++;
        }

        if(sec_idx == -1) return {-1,-1};
        int max_dist = sec_idx - first_idx;


        //2. find the minimum distance//
        prev = head;
        curr = prev->next;
        nxt = curr->next;

        idx = 1;
        first_idx = -1;
        sec_idx = -1;
        int min_dist = INT_MAX;

        while(nxt){
            if(curr->val > prev->val && curr->val > nxt->val || curr->val < prev->val && curr->val < nxt->val){
                first_idx = sec_idx;
                sec_idx = idx;

                if(first_idx != -1){
                    min_dist = min(min_dist,sec_idx-first_idx);
                }
            }
            
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;

            idx++;
        }

        return {min_dist,max_dist};
    }
};