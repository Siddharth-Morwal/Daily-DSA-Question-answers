class Solution {
public:
    int check(vector<int>& weights , int mid){
        int days = 1;
        int currLoad = 0;
      for (int w : weights) {
        if (currLoad + w <= mid) {
            currLoad += w;
        } else {
            days++;
            currLoad = w;
        }
    }
    return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        for(int w : weights) high += w;
        int res = high;
       while(low <= high){
        int mid = (low + high)/2;
        int ans = check(weights  , mid);     
        
        if(ans <= days){
          high = mid - 1;
          res = mid;
        }
        else{
          low = mid + 1;
        }
       }
       return res;
    }
};