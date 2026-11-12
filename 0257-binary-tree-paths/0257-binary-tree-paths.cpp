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
    void path_adder(TreeNode* root,string temp,vector<string>& res){

        if(root == nullptr) return;

        string ch = to_string(root->val);

        if(root->left == nullptr && root->right == nullptr){
            temp += ch;
            res.push_back(temp);
            return;
        }

        path_adder(root->left,temp + ch + "->",res);
        path_adder(root->right,temp + ch + "->",res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        path_adder(root,"",res);

        return res;
    }
};