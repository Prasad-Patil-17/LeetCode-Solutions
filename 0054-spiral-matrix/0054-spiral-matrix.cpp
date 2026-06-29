class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int min_row = 0;
        int max_row = matrix.size() - 1;

        int min_col = 0;
        int max_col = matrix[0].size() - 1;

        while(min_row <= max_row && min_col <= max_col)
        {
            // Right_traversal
            for(int j = min_col; j <= max_col; j++)
                ans.push_back(matrix[min_row][j]);
            min_row++;

            // Down_traversal
            for(int i = min_row; i <= max_row; i++)
                ans.push_back(matrix[i][max_col]);
            max_col--;

            // Left_traversal
            if(min_row <= max_row)
            {
                for(int j = max_col; j >= min_col; j--)
                    ans.push_back(matrix[max_row][j]);
                max_row--;
            }

            // Up_traversal
            if(min_col <= max_col)
            {
                for(int i = max_row; i >= min_row; i--)
                    ans.push_back(matrix[i][min_col]);
                min_col++;
            }
        }

        return ans;
    }
};