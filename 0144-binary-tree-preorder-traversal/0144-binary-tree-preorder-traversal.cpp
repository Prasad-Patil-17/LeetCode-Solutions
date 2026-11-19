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
    void pre_order(vector<int>& temp,TreeNode* root){
        if(root == nullptr) return;

        temp.push_back(root->val);

        pre_order(temp,root->left);
        pre_order(temp,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> temp;

        pre_order(temp,root);

        return temp;
    }
};