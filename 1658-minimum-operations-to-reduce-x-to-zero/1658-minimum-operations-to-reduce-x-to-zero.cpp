class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int n = nums.size();
       int res = -1;
       int target = accumulate(nums.begin() , nums.end() , 0) - x;
       if(target < 0) return -1;
       int low = 0;
       int sum = 0;
      for(int high = 0; high < n; high++){
        sum += nums[high];
        while(low <= high && sum > target){
            sum -= nums[low];
            low++;
        }
        if(sum == target){
          res = max(res , high - low + 1);
        }
      }
      if(res == -1) return -1;
      return n - res;
    }
};