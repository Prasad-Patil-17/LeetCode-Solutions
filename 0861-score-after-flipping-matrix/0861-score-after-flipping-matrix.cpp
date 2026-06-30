class Solution{
public:
    int matrixScore(vector<vector<int>>& grid){

        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            if(grid[i][0]==0){
                for(int j=0;j<cols;j++){
                    if(grid[i][j]==0)grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }

        for(int j=1;j<cols;j++){
            int num_zero=0;
            int num_one=0;

            for(int i=0;i<rows;i++){
                if(grid[i][j]==1)num_one++;
                else num_zero++;
            }

            if(num_zero>num_one){
                for(int i=0;i<rows;i++){
                    if(grid[i][j]==0)grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }

        int max_sum=0;

        for(int i=0;i<rows;i++){
            int value=0;
            for(int j=0;j<cols;j++){
                value=value*2+grid[i][j];
            }
            max_sum+=value;
        }

        return max_sum;
    }
};