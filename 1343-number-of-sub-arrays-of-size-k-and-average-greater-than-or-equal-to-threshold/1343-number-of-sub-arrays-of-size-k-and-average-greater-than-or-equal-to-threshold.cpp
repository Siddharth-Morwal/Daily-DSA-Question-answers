class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int res = 0;
        int sum = 0;
        int left = 0;
       for(int right = 0; right < n; right++){
          sum += arr[right];
          int window = right - left + 1;
          if(window == k) {
            if(sum >= k * threshold){
                res++;
            }
            sum -= arr[left];
            left++;
          }
       }
       return res;
    }
};