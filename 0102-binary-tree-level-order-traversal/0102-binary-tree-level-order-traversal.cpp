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
    int get_tree_level(TreeNode* root){
        if(root == nullptr) return 0;
        int left_trav = get_tree_level(root->left);
        int right_trav = get_tree_level(root->right);
        return 1 + max(left_trav,right_trav);
    }

    void nth_level_trav(TreeNode* root,int req_level,int curr_level,vector<int>& temp){
        if(root == nullptr) return;

        if(curr_level == req_level){
            temp.push_back(root->val);
            return;
        }

        nth_level_trav(root->left,req_level,curr_level+1,temp);
        nth_level_trav(root->right,req_level,curr_level+1,temp);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        int tree_level = get_tree_level(root);

        for(int i=1;i<=tree_level;i++){
            vector<int> temp;
            nth_level_trav(root,i,1,temp);
            res.push_back(temp);
        }

        return res;
    }
};