class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1 , INT_MAX);
        dp[0] = 0;
      for(int i = 1; i <= amount; i++){
        for(int coin : coins){
           if( i >= coin && dp[i-coin] != INT_MAX)
            dp[i] = min(dp[i - coin] + 1 , dp[i]);
        }
      }
      if(dp[amount] == INT_MAX) return -1;
      return dp[amount];  
    }
};