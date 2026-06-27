class Solution {
public:

    void transpose_matrix(vector<vector<int>>& nums,vector<vector<int>>& trans_mat){

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                trans_mat[j][i] = nums[i][j];
            }
        }
        return;
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> trans_mat(cols,vector<int> (rows));

        transpose_matrix(matrix,trans_mat);

        return trans_mat;
    }
};