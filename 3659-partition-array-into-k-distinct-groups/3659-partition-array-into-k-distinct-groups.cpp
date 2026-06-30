class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int , int> freq;
     for(int f : nums) freq[f]++;
      if(n % k) return false;
     
     for(auto& p : freq){
        if(p.second > n / k) return false;
     }
     return true;
    }
};