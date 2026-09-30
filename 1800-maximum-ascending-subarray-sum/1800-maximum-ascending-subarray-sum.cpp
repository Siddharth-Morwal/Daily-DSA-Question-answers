class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      int low = 0;
      int res = 0;
     for(int high = 0; high < n; ++high){
        if((high + 1 < n) && nums[high] < nums[high + 1]  ){
            sum += nums[high];
        }
        else {
            sum += nums[high];
            res = max(res , sum);
            sum = 0;
            low = high + 1;
        }
     }
     return res;
    } 
};