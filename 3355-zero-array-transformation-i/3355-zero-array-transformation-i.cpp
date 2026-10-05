class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> arr(nums.size() + 1 , 0);
        for(auto& p : queries){
            int l = p[0] , r = p[1];
            arr[l]--;
            arr[r+1]++;
        }

        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
          sum += arr[i];
          if(nums[i] > -sum) return false;
        }
        return true;
    }
};