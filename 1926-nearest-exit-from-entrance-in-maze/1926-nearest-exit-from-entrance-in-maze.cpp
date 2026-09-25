class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , -1 , 1};
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m ) return false;
        return true;
    } 
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int steps = 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        q.push({entrance[0] , entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        while(!q.empty()){
            int size = q.size();
            ++steps;
          while(size--){
            pair<int , int> p = q.front();
            q.pop();
          for(int k = 0; k < 4; ++k){
            int row = p.first + x[k];
            int col = p.second + y[k];
            
            if(valid(row , col , n , m) && maze[row][col] == '.' && !visited[row][col]){
               if(row == 0 || row == n-1 || col == 0 ||  col == m-1) return steps;
               visited[row][col] = true; 
                q.push({row , col});
            }
          }  
        }
        }
      return -1;
    }
};