class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int K = 2;
        vector<vector<int>>dp(K+1 , vector<int>(2 , 0));
      for(int k = 0; k <= K; k++){
        dp[k][1] =  -prices[0];
      }
      dp[0][1] = INT_MIN;
     for(int price : prices){
        for(int k = K ; k >= 1; k-- ){
            dp[k][0] = max(dp[k][0] , dp[k][1] + price );
            dp[k][1] = max(dp[k][1] , dp[k-1][0] - price );
        }
     }
     return dp[2][0];
    }
};