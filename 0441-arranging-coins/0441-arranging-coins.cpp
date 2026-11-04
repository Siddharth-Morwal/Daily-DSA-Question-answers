class Solution {
public:
    int arrangeCoins(int n) {
      return (int)(-0.5 + (double)sqrt(1.0 + 8.0*n)/2.0);
    }
};