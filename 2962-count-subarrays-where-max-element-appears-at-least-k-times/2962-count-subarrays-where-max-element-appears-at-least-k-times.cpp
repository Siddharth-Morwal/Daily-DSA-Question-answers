class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.begin() , nums.end());
        int n = nums.size();
        int low = 0;
        long long res = 0;
        int count = 0;
      for(int high = 0; high < n; ++high){
        if(nums[high] == maxEl) count++;
        
        while(count == k){
            if(nums[low] == maxEl) --count;
            ++low;
        }
         res += low;
      }
      return res;
    }
};