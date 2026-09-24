class Solution {
public:
    int x[4] = { -1 , 1 , 0 , 0};
    int y[4] = { 0 , 0 , -1 , 1};
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();

       queue<pair<int , int>> q;
       for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          if(mat[i][j] == 0){
            q.push({i , j});
          }
          else{
            mat[i][j] = INT_MAX;
           }          
          }
        }

        while(!q.empty()){
           pair<int , int> p = q.front();
           q.pop();
          for(int k = 0; k < 4 ; ++k){
            int row = p.first + x[k];
            int col = p.second + y[k];

            if(valid(row , col , n , m) && mat[row][col] > mat[p.first][p.second] + 1){
              mat[row][col] = mat[p.first][p.second] + 1;
              q.push({row , col});
          }
        }
         
     }
        return mat;
    }
};