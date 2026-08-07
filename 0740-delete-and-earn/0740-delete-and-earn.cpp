class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       int n = nums.size();
       int maxel  = *max_element(nums.begin() , nums.end());
       vector<int> points(maxel+1  , 0);
      for(int x : nums) points[x] += x;
       
       int prev2 = 0;
       int prev1 = 0;

      for(int p : points){
        int curr = max(prev1 , prev2 + p);
        prev2 = prev1;
        prev1 = curr;
      }
      return prev1;
    }
};