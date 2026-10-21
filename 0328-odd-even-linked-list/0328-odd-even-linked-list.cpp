class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Calculate length
        int length = 0;
        ListNode* trav = head;

        while (trav != NULL) {
            length++;
            trav = trav->next;
        }

        // Dummy nodes for odd and even lists
        ListNode* even_node = new ListNode(-1, nullptr);
        ListNode* even = even_node;

        ListNode* odd_node = new ListNode(-1, nullptr);
        ListNode* odd = odd_node;

        ListNode* temp = head;
        int position = 1;

        while (temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = NULL;

            if (position % 2 == 1) {
                odd->next = temp;
                odd = temp;
            } else {
                even->next = temp;
                even = temp;
            }

            temp = nextNode;
            position++;
        }

        // Join odd list to even list
        odd->next = even_node->next;

        return odd_node->next;
    }
};