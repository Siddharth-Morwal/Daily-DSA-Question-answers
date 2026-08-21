class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount+1 , 0);
        dp[0] =1;
       for(int x : coins){
        for(int a = x; a <= amount; a++){
           dp[a] += dp[a-x];
        }
       }
       return (int)dp[amount];
    }
};