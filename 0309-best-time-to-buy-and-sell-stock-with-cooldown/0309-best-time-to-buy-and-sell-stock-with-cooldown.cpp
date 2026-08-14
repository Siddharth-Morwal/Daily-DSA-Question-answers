class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
     if(n <= 1) return 0;
      vector<int> hold(n+1 , INT_MIN);  
      vector<int> cash(n+1 , INT_MIN);
      hold[0] = -prices[0];
      cash[0] = 0;

      hold[1] = max(hold[0] , cash[0] - prices[1]);
      cash[1] = max(cash[0] , hold[0] + prices[1]);

     for(int i = 2; i  < n; i++){
        hold[i] = max(hold[i-1] , cash[i-2] - prices[i]);
        cash[i] = max(cash[i-1] , hold[i-1] + prices[i]);
     }
     return cash[n-1];   
    }
};