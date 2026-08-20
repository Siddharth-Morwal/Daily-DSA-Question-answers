class Solution {
public:
    bool solve(vector<int>& nums , int i , int targetsum , vector<vector<int>>& dp) {
       if(targetsum == 0) return true;
       if(i == nums.size()) return false;
       if(dp[i][targetsum] != -1) return dp[i][targetsum];
    
        bool not_take = solve(nums , i + 1 , targetsum , dp);
        bool take = false;
       if(nums[i] <= targetsum) {
          take = solve(nums , i+1 , targetsum - nums[i] , dp);
       }
       return dp[i][targetsum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = accumulate(nums.begin() , nums.end() , 0);
      if(sum % 2) return false;
      int targetsum = sum  / 2;
      vector<vector<int>> dp(nums.size() , vector<int>(targetsum + 1 , -1 ));
      return solve(nums , 0 , targetsum , dp );
    }
};