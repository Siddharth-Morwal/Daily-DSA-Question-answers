class Solution {
public:
        bool check(int x , vector<int>& arr){
            return arr[x] < arr[x+1];
        }
    int peakIndexInMountainArray(vector<int>& arr) {
       int low = 0;
        int high = arr.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
          if(check(mid , arr)){
            low = mid+1;
          }
          else{
            high = mid;
          }
        }
        return low;
    }
};