class Solution {
public:
    int xorsum(vector<int>& nums , int idx , int curr){
        if(idx == nums.size()) return curr;

        int welement = xorsum(nums , idx + 1 , curr^nums[idx]);
        int nowelement = xorsum(nums , idx + 1 , curr);

        return welement + nowelement;
    }
    int subsetXORSum(vector<int>& nums) {
      return xorsum(nums , 0 , 0);
    }
};