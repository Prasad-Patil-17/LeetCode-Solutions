class Solution {
public:
    TreeNode* tree_builder(vector<int>& preorder,int pre_low,int pre_high,vector<int>& inorder,int in_low,int in_high){

        if(pre_low > pre_high || in_low > in_high) return nullptr;

        //consider first node as root from preorder traversal//
        TreeNode* root = new TreeNode(preorder[pre_low]);

        if(pre_low == pre_high || in_low == in_high) return root;
        
        //find the root node in the inorder traversal//
        int i = in_low;
        while(i <= in_high){
            if(inorder[i] == preorder[pre_low]) break;
            i++;
        }

        //ith node in the inorder is the root node//

        int left_count = i - in_low;
        int right_count = in_high - i;
        
        root->left = tree_builder(preorder,pre_low+1,pre_low+left_count,inorder,in_low,i-1);
        root->right = tree_builder(preorder,pre_low+left_count+1,pre_high,inorder,i+1,in_high);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();

        return tree_builder(preorder,0,n-1,inorder,0,n-1);
    }
};