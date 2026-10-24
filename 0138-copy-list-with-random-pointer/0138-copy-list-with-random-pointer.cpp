
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;

        // Step 1: Create a copy of every node
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Connect next and random pointers
        curr = head;

        while (curr != nullptr) {
            Node* copyNode = mp[curr];

            if (curr->next != nullptr) {
                copyNode->next = mp[curr->next];
            }

            if (curr->random != nullptr) {
                copyNode->random = mp[curr->random];
            }

            curr = curr->next;
        }

        return mp[head];
    }
};
