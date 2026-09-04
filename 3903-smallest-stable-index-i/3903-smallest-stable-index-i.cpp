class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n = nums.size();

       vector<int> stb(n);
       stb[0] = nums[0];
      
      for(int i = 1; i < n; ++i)
        stb[i] = max(stb[i-1] , nums[i]);
      
      int minN = INT_MAX;
     for(int i = n - 1; i >= 0; --i){
        minN = min(nums[i] , minN);
        stb[i] -= minN;
     }

     for(int i = 0; i < n; ++i)
        if(stb[i] <= k) return i;
      return -1;
    }
};