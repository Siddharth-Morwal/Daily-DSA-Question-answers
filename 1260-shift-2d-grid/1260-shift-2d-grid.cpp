class Solution {
public:
    void reverse(vector<vector<int>> &grid , int l , int r , int n ){
        while(l < r){
            swap(grid[l/n][l%n] , grid[r/n][r%n]);
            l++;
            r--;    
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= (m*n);
      reverse(grid , 0 , m*n - 1 , n);
      reverse(grid , 0 ,k - 1 , n);
      reverse(grid , k , m*n - 1 , n);

      return grid;
    }
};