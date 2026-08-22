class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
      for(string s : strs){
        int zc = 0;
        int oc = 0;
       for(char c : s){
        if(c == '0') zc++;
        else oc++;
       }

       for(int z = m; z >= zc; z--){
        for(int o = n; o >= oc; o--){
          dp[z][o] = max(dp[z][o] , dp[z - zc][o - oc]+1);
        }
       }
      }
      return dp[m][n];
    }
};