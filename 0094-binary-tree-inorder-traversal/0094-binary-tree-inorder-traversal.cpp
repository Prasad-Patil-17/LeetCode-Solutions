class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        
        TreeNode* node = root;

        while (!st.empty() || node != nullptr) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* temp = st.top();
                st.pop();

                res.push_back(temp->val);

                node = temp->right;
            }
        }

        return res;
    }
};