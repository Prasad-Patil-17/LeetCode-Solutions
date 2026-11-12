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
    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p == nullptr && q == nullptr) return true;

        if(p == nullptr || q == nullptr) return false;

        if(p->val != q->val) return false;

        bool left_tree = isSameTree(p->left, q->left);
        bool right_tree = isSameTree(p->right, q->right);

        return left_tree && right_tree;
    }

    TreeNode* invert_tree(TreeNode* root) {
        if(root == nullptr) return root;

        swap(root->left, root->right);
        
        invert_tree(root->left);
        invert_tree(root->right);

        return root;
    }

    bool isSymmetric(TreeNode* root) {
        
        if(root == nullptr) return true;

        TreeNode* left_side = invert_tree(root->left);

        return isSameTree(left_side,root->right);
    }
};