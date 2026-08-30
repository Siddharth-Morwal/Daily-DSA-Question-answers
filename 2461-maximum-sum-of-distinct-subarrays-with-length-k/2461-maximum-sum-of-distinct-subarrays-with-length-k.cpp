class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       long long res = 0;
      unordered_set<int> mp;
       long long low = 0;
       long long sum = 0;
     for(int high = 0; high < n; high++ ){
        if(mp.find(nums[high]) == mp.end()){
          sum += nums[high];
          mp.insert(nums[high]);
        
        if(high - low + 1 == k){
           res = max(res , sum);
           sum -= nums[low];
           mp.erase(nums[low]);
           low++;
         }
        }
        else{
            while(nums[high] != nums[low]){
                sum -= nums[low];
                mp.erase(nums[low]);
                low++;
            }
            low++;
        }
     }

      return res;   
    }
};