class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      vector<vector<int>>prefX(row+1 , vector<int>(col + 1));
      vector<vector<int>>prefY(row+1 , vector<int>(col + 1));

      int submatrices = 0;

      for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= col; ++j){

            prefX[i][j] = prefX[i-1][j] + prefX[i][j-1] - prefX[i-1][j-1];
            prefY[i][j] = prefY[i-1][j] + prefY[i][j-1] - prefY[i-1][j-1];

            if(grid[i-1][j-1] == 'X'){
                prefX[i][j]++;
            }
            else if(grid[i-1][j-1] == 'Y'){
                prefY[i][j]++;
            }
             if (prefX[i][j] > 0 && prefX[i][j] == prefY[i][j]) 
                {
                    submatrices++;
                }
        }
      }
      return submatrices;
    }
};