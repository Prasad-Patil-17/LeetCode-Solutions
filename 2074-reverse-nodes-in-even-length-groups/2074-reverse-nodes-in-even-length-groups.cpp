class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prevGroupTail = head;
        int groupSize = 2;

        while (prevGroupTail->next != nullptr) {
            ListNode* groupHead = prevGroupTail->next;
            ListNode* curr = groupHead;
            int count = 0;

            // Count the actual nodes in this group
            while (count < groupSize && curr != nullptr) {
                curr = curr->next;
                count++;
            }

            // Reverse only if the actual group length is even
            if (count % 2 == 0) {
                ListNode* prev = curr;
                ListNode* node = groupHead;

                for (int i = 0; i < count; i++) {
                    ListNode* nextNode = node->next;
                    node->next = prev;
                    prev = node;
                    node = nextNode;
                }

                prevGroupTail->next = prev;
                prevGroupTail = groupHead;
            } else {
                // Leave the group unchanged
                for (int i = 0; i < count; i++) {
                    prevGroupTail = prevGroupTail->next;
                }
            }

            groupSize++;
        }

        return head;
    }
};
