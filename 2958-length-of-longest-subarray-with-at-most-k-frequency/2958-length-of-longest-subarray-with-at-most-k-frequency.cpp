class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> freq;
        int res = 0;
        int low = 0;
      for(int i = 0; i < n; i++){
        ++freq[nums[i]];
        
        while(freq[nums[i]] > k){
            --freq[nums[low]];
            ++low;
        }
        res = max(res , i - low + 1);
      }
      return res;
    }
};