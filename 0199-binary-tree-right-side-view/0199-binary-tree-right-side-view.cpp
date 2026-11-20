class Solution {
public:
    int total_levels(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(total_levels(root->left),total_levels(root->right));
    }

    void nth_level_trav(TreeNode* root,vector<int>& res,int curr_level,int level_count){
        if(root == nullptr) return;

        if(level_count == curr_level){
            res[curr_level] = root->val;
            return;
        }

        nth_level_trav(root->left,res,curr_level,level_count+1);
        nth_level_trav(root->right,res,curr_level,level_count+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res(total_levels(root),0);
        int levels = total_levels(root);

        for(int i=0;i<levels;i++){
            nth_level_trav(root,res,i,0);
        }

        return res;

    }
};