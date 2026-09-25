class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0 };
    int y[4] = {0 , 0 , -1 , 1 };
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    bool dfs(int i , int j, int n , int m , vector<vector<int>>& grid1, vector<vector<int>>& grid2 ,vector<vector<bool>>& visited){
        visited[i][j] = true;
        
        bool isSubisland = true;
        
        if(grid1[i][j] == 0) isSubisland = false;
        for(int k = 0; k < 4; ++k){
            int row = i + x[k];
            int col = j + y[k];
           
           if(valid(row , col , n , m) && grid2[row][col] == 1 && !visited[row][col] ){
            if( !dfs(row , col , n , m , grid1 , grid2 , visited))
              isSubisland = false;
           }
        }
        return isSubisland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int subislands = 0;

        vector<vector<bool>>visited(n , vector<bool>(m , false));

        for(int x = 0; x < n*m; ++x){
          int i = x / m;
          int j = x % m;
          
          if(grid2[i][j] == 1 && !visited[i][j]){
           if(dfs(i , j , n , m , grid1 , grid2 , visited))
            ++subislands;
          }
        }
        return subislands;
    }
};