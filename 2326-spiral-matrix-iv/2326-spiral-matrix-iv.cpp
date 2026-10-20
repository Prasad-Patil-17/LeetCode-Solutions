/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        //1. Generate the (mxn) matrix and initialize with -1;
        vector<vector<int>> mat(m,vector<int> (n,-1));

        //2. initialize the 4 pointers that mark the boundary of the matrix//
        int min_row = 0;
        int max_row = m - 1;
        int min_col = 0;
        int max_col = n - 1;

        ListNode* temp = head;

        while(min_row <= max_row && min_col <= max_col){
            //1. Traverse from min_col to max_col;
            for(int i=min_col;i<=max_col;i++){
                if(temp == NULL) return mat;
                mat[min_row][i] = temp->val;
                temp = temp->next;
            }
            min_row++;

            //2. Traverse from the min_row to max_row;
            for(int i=min_row;i<=max_row;i++){
                if(temp == NULL) return mat;
                mat[i][max_col] = temp->val;
                temp = temp->next;
            }
            max_col--;

            //3. Traverse from max_col to min_col;
            for(int i=max_col;i>=min_col;i--){
                if(temp == NULL) return mat;
                mat[max_row][i] = temp->val;
                temp = temp->next;
            }
            max_row--;

            //4. Traverse from max_row to min_row;
            for(int i=max_row;i>=min_row;i--){
                if(temp == NULL) return mat;
                mat[i][min_col] = temp->val;
                temp = temp->next;
            }
            min_col++;
            
            if (min_row > max_row || min_col > max_col) break;
        }

        return mat;
    }
};