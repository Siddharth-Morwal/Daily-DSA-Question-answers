class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , -1 , 1};
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int per = 0;
        queue<pair<int , int>> q;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        bool found = false;
        for(int i = 0; i < n; ++i){
         for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1){
              q.push({i , j});
              visited[i][j] = true;
              found = true;
              break;
            }
         }
         if(found) break;
        }
              while(!q.empty()){
                auto p = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i){
                    int row = p.first + x[i];
                    int col = p.second + y[i];
                   if(!valid(row , col , n , m)) ++per;
                   else if(grid[row][col] == 0) ++per;
                   else if(grid[row][col] == 1 && !visited[row][col]){
                       visited[row][col] = true;
                       q.push({row , col});
                   }
                }
              }
        return per;
    }
};