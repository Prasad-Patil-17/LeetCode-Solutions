/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void post_order(vector<int>& temp,TreeNode* root){

        if(root == nullptr) return;

        post_order(temp,root->left);
        post_order(temp,root->right);
        temp.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> temp;

        post_order(temp,root);

        return temp;
    }
};