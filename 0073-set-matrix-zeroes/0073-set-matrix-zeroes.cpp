class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<pair<int,int>> zeros; 

  for(int x = 0; x < n*m; ++x){
    int row = x /m;
    int col = x % m;
   if(matrix[row][col] == 0){
    zeros.push_back({row , col});
   }
  }
     for(auto [row, col] : zeros) {
    for(int a = 0 , b = 0; a < m || b < n ; ++a , ++b){
        if(a < m) matrix[row][a] = 0;
        if(b < n) matrix[b][col] = 0;
      }
    }
    }
};