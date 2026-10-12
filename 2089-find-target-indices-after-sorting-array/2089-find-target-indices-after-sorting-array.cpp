class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;
        vector<int> res;
      while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target){
           if(nums[mid] == target) first = mid;
           high = mid - 1;
        }
        else low = mid + 1;
      }
       
       if(first == -1) return res;

       while(first < n && nums[first] == target){
          res.push_back(first);
          ++first;
       }
       
      return res;
    }
};