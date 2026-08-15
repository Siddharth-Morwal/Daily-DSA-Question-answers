class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(k+1 , vector<int>(2 , 0));
      for(int i = 0; i <= k; i++){
        dp[i][1] =  -prices[0];
      }
      dp[0][1] = INT_MIN;
     for(int price : prices){
        for(int j = k ; j >= 1; j-- ){
            dp[j][0] = max(dp[j][0] , dp[j][1] + price );
            dp[j][1] = max(dp[j][1] , dp[j-1][0] - price );
        }
     }
     return dp[k][0];  
    }
};