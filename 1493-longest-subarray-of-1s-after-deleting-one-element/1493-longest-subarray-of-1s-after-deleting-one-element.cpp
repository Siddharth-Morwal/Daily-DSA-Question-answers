class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int n = nums.size();
      int res = 0;
      int countzero = 0;
      int low = 0;
     for(int high = 0; high < n; high++){
        if(nums[high] == 0){
            countzero++;
        }
       
        while(countzero > 1){
            if(nums[low] == 0)
                countzero--;
            low++;
        }
        res = max(res , high - low );
     }
     return res;  
    }
};