class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1);
        prefix[0] = 0;
      for(int i = 1; i <=n ; i++){
        prefix[i] = prefix[i-1] + nums[i-1];
      }
       long long res = LLONG_MIN;
        unordered_map<long long , long long> freq;
        
       for(int i = 0; i < n; i++){
        long long target1 = nums[i] - k;
        long long target2 = nums[i] + k;

        if(freq.count(target1)){
            res = max(res , prefix[i+1] - freq[target1]);
        }

        if(freq.count(target2)){
            res = max(res , prefix[i+1] - freq[target2]);
        }

        if(!freq.count(nums[i])){
            freq[nums[i]] = prefix[i];
        }
        else{
            freq[nums[i]] = min(prefix[i] , freq[nums[i]]);
        }
       }
        return res == LLONG_MIN ? 0 : res;
    }
};