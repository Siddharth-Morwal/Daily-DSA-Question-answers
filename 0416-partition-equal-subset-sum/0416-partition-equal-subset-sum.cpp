class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = accumulate(nums.begin() , nums.end() , 0);
      if(sum % 2) return false;
      int targetsum = sum  / 2;
      vector<bool> dp(targetsum + 1 , false);
      dp[0] = true;
     for(int x : nums){
      for(int s = targetsum; s >= x; s--){
        dp[s] = dp[s] || dp[s-x];
      }
     }
     return dp[targetsum];
    }
};