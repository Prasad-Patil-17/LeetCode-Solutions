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
    void helper(TreeNode* root,long long target_sum,int& count){
        if(root == nullptr) return;

        if(target_sum == root->val) count += 1;

        helper(root->left,(long long)target_sum - root->val,count);
        helper(root->right,(long long)target_sum - root->val,count);

    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return 0;

        int count = 0;

        helper(root,(long long)targetSum,count);

        return count + pathSum(root->left,(long long)targetSum) + pathSum(root->right,(long long)targetSum);
    }
};