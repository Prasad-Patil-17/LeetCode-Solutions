class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right)
            return head;

        ListNode* left_node = head;
        ListNode* prev_left_node = NULL;

        ListNode* right_node = head;
        ListNode* next_right_node = NULL;

        // 1. Find the left node and its previous node
        int count = 1;

        while (left_node != NULL && count < left) {
            prev_left_node = left_node;
            left_node = left_node->next;
            count++;
        }

        // 2. Find the right node
        count = 1;

        while (right_node != NULL && count < right) {
            right_node = right_node->next;
            count++;
        }

        if (left_node == NULL || right_node == NULL)
            return head;

        // 3. Save the node after the right boundary
        next_right_node = right_node->next;

        // 4. Isolate the required section
        if (prev_left_node != NULL)
            prev_left_node->next = NULL;

        right_node->next = NULL;

        // 5. Reverse only the isolated section
        ListNode* rev_head = reverseList(left_node);

        // 6. Find the tail of the reversed section
        ListNode* tail = rev_head;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        // 7. Reconnect the reversed section
        if (prev_left_node != NULL) {
            prev_left_node->next = rev_head;
        } else {
            head = rev_head;
        }

        tail->next = next_right_node;

        return head;
    }
};