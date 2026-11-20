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
    int tot_level(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(tot_level(root->left),tot_level(root->right));
    }
    void pre_order(TreeNode* root,vector<int>& res,int curr_level){
        if(root == nullptr) return;

        res[curr_level] = root->val;

        pre_order(root->left,res,curr_level+1);
        pre_order(root->right,res,curr_level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res(tot_level(root),0);

        pre_order(root,res,0);

        return res;
    }
};