class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums , k) - atmostk(nums , k-1);
    }
      int atmostk(vector<int>& nums , int k){
        int low = 0;
        int n = nums.size();
        int odd = 0;
        int count = 0;
      for(int high = 0; high < n; high++){
        if(nums[high] % 2 == 1) odd++;
        while(odd > k && low <= high){
           if(nums[low] % 2 == 1) odd--;
            low++;
        }
         count += (high - low + 1);
      }
        return count;
      }
    
};