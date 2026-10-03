class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n , vector<int>(n , 0));
      int top = 0 , bottom = n - 1 , left = 0 , right = n - 1 , nums = 1;
     while(top <= bottom && left <= right){
      for(int i = left; i <= right; ++i){
        res[top][i] = nums++;
      }
      ++top;

      if(top <= bottom){
        for(int j = top; j <= bottom; ++j){
           res[j][right] = nums++;
        }
        --right;
      }

      if(top <= bottom && left <= right){
         for (int k = right; k >= left; --k) {
                res[bottom][k] = nums++;
            }
            --bottom;
        }

        if (top <= bottom && left <= right) {
            for (int l = bottom; l >= top; --l) {
                res[l][left] = nums++;
            }
            ++left;
        }
     }
      return res;
    }
};