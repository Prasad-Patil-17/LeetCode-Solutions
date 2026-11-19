/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == nullptr) return root;

        if(root == p || root == q) return root;

        TreeNode* left_search = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_search = lowestCommonAncestor(root->right,p,q);

        if(left_search != nullptr && right_search != nullptr) return root;
        else if(left_search != nullptr && right_search == nullptr) return left_search;

        return right_search;
    }
};