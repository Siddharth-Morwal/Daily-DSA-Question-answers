class Solution {
public:
    // int binarysearch(vector<int>& nums , int l , int r , int x){
    //     while(l <= r && r < nums.size()){
    //       int mid = (l + r) / 2;
    //       if(nums[mid] >= x) r = mid - 1;
    //       else l = mid + 1;
    //     }
    //     return l;
    // }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int count = 0;
    //    for(int i = 0; i < n - 2; ++i){
    //      int k = i + 2;
    //      for(int j = i + 1; j < n - 1; ++j){
    //        k = binarysearch(nums , k , n - 1 , nums[i] + nums[j] );
    //        count += k - j - 1;
    //      }
    //    }
    //    return count;
    // }

 
    for(int i = 0; i < n - 2; i++){
        int k = i + 2;
      for(int j = i + 1 ; j < n - 1 && nums[i] != 0 ; j++){
        while(k < n && nums[i] + nums[j] > nums[k]){
            k++;
            count += k - j - 1;
        }
      }
     }
     return count;
    }
};