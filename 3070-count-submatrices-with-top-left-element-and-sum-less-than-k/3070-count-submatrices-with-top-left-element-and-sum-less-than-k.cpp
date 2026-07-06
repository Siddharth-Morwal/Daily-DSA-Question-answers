class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prefixmat(m);
        int res = 0;
      for(int i = 0; i < n; i++){
        int rows = 0;
       for(int j = 0; j < m; j++){
         prefixmat[j] += grid[i][j];
         rows += prefixmat[j];
         if(rows <= k){
            res++;
         }
       }
      }
      return res;
    }
};