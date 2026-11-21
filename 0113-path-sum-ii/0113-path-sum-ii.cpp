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
    void helper(TreeNode* root,vector<vector<int>>& res,vector<int> temp,int target_sum){

        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            if(target_sum == root->val){
                temp.push_back(root->val);
                res.push_back(temp);
            }
            return;
        }

        temp.push_back(root->val);
        
        helper(root->left,res,temp,(target_sum-root->val));
        helper(root->right,res,temp,(target_sum-root->val));

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;

        helper(root,res,temp,targetSum);

        return res;
    }
};