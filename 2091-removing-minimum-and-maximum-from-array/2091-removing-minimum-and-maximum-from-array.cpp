class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
      int n = nums.size();

      int minelidx = min_element(begin(nums), end(nums)) - begin(nums);
      int maxelidx = max_element(begin(nums) , end(nums)) - begin(nums);

      int left = min(minelidx , maxelidx);
      int right = max(minelidx , maxelidx);

      return min({left + 1 + n - right , right + 1 , n - left});
    }
};