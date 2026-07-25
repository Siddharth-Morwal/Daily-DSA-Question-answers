class Solution {
public:
    int maxProduct(int n) {
      int firstmax = 0;
      int secondmax = 0;
     while(n > 0){
        int x = n % 10;
        if(x > firstmax){
            secondmax = firstmax;
            firstmax = x;
        }
        else if(x > secondmax){
            secondmax = x;
        }
        n /= 10;
     }
     return firstmax * secondmax;
    }
};