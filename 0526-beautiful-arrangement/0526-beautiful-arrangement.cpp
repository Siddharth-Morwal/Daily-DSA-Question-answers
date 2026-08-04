class Solution {
public:
    int countArrangement(int n) {
      vector<int> nums(n , 0);
     for(int i = 0; i < n; i++){
        nums[i] = i+1;
     }
      int count = 0;
      calculate(n , nums , 0 , count);
      return count;
    }
    void calculate(int n ,vector<int>& nums , int idx , int& count){
      if(idx == n){
        count++;
        return;
      }
      for(int i = idx; i < n; i++){
        swap(nums[i] , nums[idx]);
        if(nums[idx] % (idx + 1) == 0 || (idx + 1) % nums[idx] == 0){
            calculate(n , nums , idx + 1 , count);
        }
        swap(nums[i] , nums[idx]);
      }
    }
    
};