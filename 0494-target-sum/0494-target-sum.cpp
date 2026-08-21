class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        if((total + target) % 2 != 0 )
           return 0;
           if(abs(target) > total ) return 0;

        int subtarget =  ( total + target ) / 2;
        vector<int> dp(subtarget+1 , 0);
        dp[0] = 1;
       for(int x : nums){
         for(int s = subtarget; s >= x; s--){
            dp[s] += dp[s-x];
         }
       }
       return dp[subtarget];
    }
};