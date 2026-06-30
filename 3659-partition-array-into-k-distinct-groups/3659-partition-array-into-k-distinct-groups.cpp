class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int , int> freq;
      int grp = n / k;
     for(int f : nums){
        freq[f]++;
       if(freq[f] > grp) return false;
     }
      if(n % k) return false;
     return true;
    }
};