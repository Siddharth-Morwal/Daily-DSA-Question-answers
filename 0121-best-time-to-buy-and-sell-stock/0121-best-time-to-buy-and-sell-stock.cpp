class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int profit  = 0;
      int currstock = prices[0];
     for(int i = 1; i < n; i++){
       if(currstock > prices[i]) currstock = prices[i];
        profit = max(profit , prices[i] - currstock);   
     }
     return profit;
    }
};