class Solution {
public:
    int arrangeCoins(int n){
     long long low = 0;
     long long high = n;
     while(low <= high){
        long long mid = low + (high - low)/2;
        long long coins_needed = mid*(mid + 1 ) / 2;
        if(coins_needed ==  n) return (int) mid;
        else if(coins_needed < n) low = mid + 1;
        else high = mid - 1;
     }
     return (int)high;
     // return (int)(-0.5 + (double)sqrt(1.0 + 8.0*n) / 2.0);
    }
};