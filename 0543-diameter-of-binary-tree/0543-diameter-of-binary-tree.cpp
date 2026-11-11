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

    void helper(int& max_diameter,TreeNode* root){

        if(root == nullptr) return;

        int left_tree = get_level(root->left);
        int right_tree = get_level(root->right);

        int diameter = left_tree + right_tree;
        max_diameter = max(diameter,max_diameter);

        helper(max_diameter,root->left);
        helper(max_diameter,root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int max_diameter = 0;

        helper(max_diameter,root);

        return max_diameter;

    }
};