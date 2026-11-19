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
    void in_order(vector<int>& temp,TreeNode* root){

        if(root == nullptr) return;

        in_order(temp,root->left);
        temp.push_back(root->val);
        in_order(temp,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;

        in_order(temp,root);

        return temp;
    }
};