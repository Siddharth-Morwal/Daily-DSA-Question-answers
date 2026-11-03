class Solution {
public:
    int minMoves(vector<int>& nums) {
      int maxel = *max_element(nums.begin() , nums.end());
      int moves = 0;
      for(int num : nums)
        moves +=(maxel - num);
      return moves;
    }
};