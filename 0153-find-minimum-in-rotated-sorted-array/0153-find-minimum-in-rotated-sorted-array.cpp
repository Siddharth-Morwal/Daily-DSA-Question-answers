class Solution {
public:
    bool check(int mid , vector<int>& nums){
        return nums[mid] > nums.back();
    }
    int findMin(vector<int>& nums) {
      int low = 0;
      int high = nums.size() - 1;

      while(low < high){
        int mid = (low + high) / 2;
        if(check(mid , nums)){
            low = mid+1;
        }
        else{
            high = mid;
        }
      }
    return nums[low] ;
    }
};