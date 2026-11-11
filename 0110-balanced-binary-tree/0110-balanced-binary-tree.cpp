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
    int get_level(TreeNode* root){
        if(root == nullptr) return 0;

        int left_tree = get_level(root->left);
        int right_tree = get_level(root->right);

        return 1 + max(left_tree,right_tree);
    }

    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr) return true;

        int left_height = get_level(root->left) + 1;
        int right_height = get_level(root->right) + 1;

        if(abs(left_height - right_height) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};