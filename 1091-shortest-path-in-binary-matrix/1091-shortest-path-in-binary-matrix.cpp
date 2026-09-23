class Solution {
public:
    int x[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int y[8] = {0, 0, -1, 1, -1, 1, 1, -1};
    bool valid(int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        int res = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                if( r == n - 1 && c == n - 1) return res;

               for(int i = 0; i < 8; ++i){
                int row = r + x[i];
                int col = c + y[i];
              if(valid(row , col , n) && grid[row][col] == 0){
                q.push({row , col});
                grid[row][col] = 1;
                }
               }
            }
            res++;
        }
        return -1;
    }
};