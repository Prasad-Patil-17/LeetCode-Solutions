class Solution {
public:
    void take_transpose(vector<vector<int>>& nums){

        for(int i=0;i<nums.size();i++){
            bool same = false;

            for(int j=0;j<nums[i].size();j++){
                if(i == j){
                    same = true;
                    break;
                }
                swap(nums[i][j],nums[j][i]);
            }

            if(same) continue;
        }

        return;
    }

    void reverse_each_row(vector<vector<int>>& matrix){

        int n = matrix.size();
        for(int i = 0; i < n; i++){

            int left = 0;
            int right = n - 1;

            while(left < right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }

        return;
    }

    void rotate(vector<vector<int>>& matrix) {
        
        take_transpose(matrix);
        reverse_each_row(matrix);

        return;
    }
};