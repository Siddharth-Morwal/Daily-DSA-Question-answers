class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int res  = 0;
        vector<vector<bool>> visited( n , vector<bool>(m , false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int area  = 0;
                    q.push({i, j});
                    visited[i][j] = true; 
                    while(!q.empty()){
                       auto p = q.front();
                       q.pop();
                      ++area;

                      for(int k = 0; k < 4; ++k){
                        int row = p.first + x[k];
                        int col = p.second + y[k];

                        if(valid(row , col , n , m) && grid[row][col] == 1 && visited[row][col] == false){
                            q.push({row , col});
                            visited[row][col] = true;
                        }
                      }
                    }
                  res = max(res , area);
                }
            }
        }
        return res;
    }
};