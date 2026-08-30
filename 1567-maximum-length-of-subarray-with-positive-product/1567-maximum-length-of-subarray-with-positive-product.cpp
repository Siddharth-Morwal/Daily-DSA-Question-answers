class Solution {
public:
    int getMaxLen(vector<int>& nums) {
     int n = nums.size();
        vector<int> prefix(n + 1);
        prefix[0] = 1;
        int res = 0;
        int firstpos = 0;
        int firstneg = -1;
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] == 0) {
                prefix[i] = 0;
                firstpos = i;
                firstneg = -1;
                 continue;
            }
          
          if(nums[i-1] > 0){
            prefix[i] = prefix[i-1];
           
          }
          else{
            prefix[i] = -prefix[i-1];
          }
         
         if(prefix[i-1] == 0){
            prefix[i] = (nums[i-1] > 0) ? 1 : -1;
         }

          if(prefix[i] == 1){
             res = max(res , i - firstpos);
          }

          else{
            if(firstneg == -1)
               firstneg = i;
            
            res = max(res , i - firstneg);
          }
        }
        return res;
    }
};