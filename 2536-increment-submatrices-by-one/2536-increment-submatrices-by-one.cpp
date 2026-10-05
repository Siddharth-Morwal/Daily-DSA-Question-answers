class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
      vector<vector<int>> diff(n+1 , vector<int>(n+1));
      for(auto& p : queries){
        int row1 = p[0] , col1 = p[1] , row2 = p[2] , col2 = p[3];
        diff[row1][col1]++;
        diff[row2 + 1][col2 + 1]++;
        diff[row1][col2+1]--;
        diff[row2+1][col1]--;
      }
      
       vector<vector<int>> mat(n , vector<int>(n));
      for(int x = 0; x < n*n; ++x){
        int row = x / n;
        int col = x % n;

        int above = (row == 0) ? 0 : mat[row-1][col];
        int left  = (col == 0) ? 0 : mat[row][col - 1];
        int diag = (row == 0 || col == 0) ? 0 : mat[row - 1][col - 1];

        mat[row][col] = diff[row][col] + above + left - diag;
      }
       
      return mat;
    }
};