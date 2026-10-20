class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 1. Generate the matrix and initialize with -1
        vector<vector<int>> mat(n, vector<int>(n, -1));

        // 2. Initialize the four boundaries
        int min_row = 0;
        int max_row = n - 1;
        int min_col = 0;
        int max_col = n - 1;

        int count = 1;

        while (min_row <= max_row && min_col <= max_col) {

            // 1. Traverse from left to right
            for (int i = min_col; i <= max_col; i++){
                mat[min_row][i] = count++;
            }
            min_row++;

            // 2. Traverse from top to bottom
            for (int i = min_row; i <= max_row; i++) {
                mat[i][max_col] = count++;
            }
            max_col--;

            if (min_row > max_row || min_col > max_col) break;

            // 3. Traverse from right to left
            for (int i = max_col; i >= min_col; i--) {
                mat[max_row][i] = count++;
            }
            max_row--;

            // 4. Traverse from bottom to top
            for (int i = max_row; i >= min_row; i--) {
                mat[i][min_col] = count++;
            }
            min_col++;

            if (min_row > max_row || min_col > max_col) break;
        }

        return mat;
    }
};