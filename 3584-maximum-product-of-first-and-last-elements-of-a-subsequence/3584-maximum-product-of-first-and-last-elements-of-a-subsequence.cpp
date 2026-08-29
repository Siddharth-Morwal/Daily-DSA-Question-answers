class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
       long long mini = INT_MAX;
       long long maxi = INT_MIN;
       long long res = LLONG_MIN;
     for(int i = 0;  i < nums.size(); i++){
       if(i >= m-1 ){
        mini = min(mini ,1LL * nums[i + 1 - m] );
        maxi = max(maxi , 1LL * nums[i+1 - m]);
      res = max({res , mini * nums[i] , maxi * nums[i]});
      }
     }
     return res;
    }
};