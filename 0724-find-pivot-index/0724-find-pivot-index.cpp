class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum = 0;
       int n = nums.size();
      for(int i = 0; i < n; i++){
        sum += nums[i];
      }
      
      int left = 0;
     for(int j = 0; j < n; j++){
        int right = sum - left - nums[j]; 
       if(left == right){
         return j;
       }
       left += nums[j];
     }
     return -1;

    }
    

};