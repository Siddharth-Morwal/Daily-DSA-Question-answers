class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1 , amount + 1);
        dp[0] = 0;
      for(int x : coins){
        for(int a = x; a <= amount; a++){
            dp[a] = min(dp[a - x] + 1 , dp[a]);
        }
      }
      if(dp[amount] == amount+1) return -1;
      return dp[amount];  
    }
};