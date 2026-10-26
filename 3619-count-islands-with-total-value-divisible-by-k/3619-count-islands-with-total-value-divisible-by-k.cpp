class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , -1 , 1};
    bool valid(int i , int j , int n , int m){
      if(i < 0 || i >= m || j < 0 || j >= n) return false;
      return true;
    }
    long long  dfs(int i , int j , int n , int m , int divisor ,  vector<vector<int>>& grid , vector<vector<bool>>& visited){
      visited[i][j] = true;
      long long sum = grid[i][j];
      for(int d = 0; d < 4; d++){
        int row = i + x[d];
        int col = j + y[d];

        if(valid(row , col , n , m ) &&  !visited[row][col] && grid[row][col] != 0)
         sum += dfs(row , col , n , m , divisor , grid , visited);
      }
      return sum; 
    }
    int countIslands(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      if(m == 0) return 0;
      int n = grid[0].size();
      int islands = 0;
      vector<vector<bool>> visited(m , vector<bool>(n , false));
     for(int x = 0; x < n*m; x++){
       int i = x / n;
       int j = x % n;

       if(grid[i][j] != 0 && !visited[i][j]){
          long long sum = dfs(i , j , n , m  , k , grid , visited);
          if(sum % k == 0) islands++;
       }
     }
     return islands;
    }
};