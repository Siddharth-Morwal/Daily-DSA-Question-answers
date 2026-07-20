class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= (m*n);
       vector<vector<int>> ans(m , vector<int>(n));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
           int current_index = i*n + j;
           int new_index = (current_index + k ) % (m*n);

           int new_row = new_index / n;
           int new_column = new_index % n;  

           ans[new_row][new_column] = grid[i][j];
       }
      }
      return ans;
    }
};