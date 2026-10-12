class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
      int n = nums.size();
     for(int &num : nums) num%= k;
      int low  = 0 , high = 0;
      int res = 1;
      while(high < n){
        if(nums[low] != nums[high]) low = high;

        long long sum = 1LL * nums[high] * ( high - low + 1);

        if(sum % k == nums[high]) res = max(res , high - low  + 1);
        high++;
      }
      return res;
    }
};