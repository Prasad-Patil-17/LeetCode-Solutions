class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        stack<Node*> st;
        Node* curr = head;

        while (curr != nullptr) {
            // If the current node has a child
            if (curr->child != nullptr) {
                // Save the original next node
                if (curr->next != nullptr) {
                    st.push(curr->next);
                }

                // Connect current node to its child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            // If we reach the end of a list,
            // reconnect the saved next node
            if (curr->next == nullptr && !st.empty()) {
                Node* nextNode = st.top();
                st.pop();

                curr->next = nextNode;
                nextNode->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};
