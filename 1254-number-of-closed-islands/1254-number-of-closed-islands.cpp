class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , -1 , 1};
    bool valid(int i , int j , int n , int m){
      if(i < 0 || i >= n || j < 0 || j >= m) return false;
      return true;
    }
    bool dfs(int i , int j , int n , int m , vector<vector<int>>& grid , vector<vector<bool>>& visited){
        visited[i][j] = true;
        bool closed = !(i == 0 || i == n-1 || j == 0 || j == m-1);
       for(int k = 0; k < 4; ++k){
        int row = i + x[k];
        int col = j + y[k];

        if(valid(row , col , n , m) && grid[row][col] == 0 && !visited[row][col]){
         bool childClosed = dfs(row , col , n , m , grid , visited);
         closed = closed && childClosed;
        }
       }
       return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
       for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 0 && !visited[i][j]){
               if(dfs(i , j , n , m , grid , visited))
               ++islands;
            }
        }
       }
       return islands;
    }
};