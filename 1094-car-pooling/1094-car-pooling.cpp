class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      int totalcap = 0;
      int arr[1001] = {};
     for(auto& q : trips){
        int pass = q[0] , from = q[1] , to = q[2];
        
        for(int i = from; i < to; ++i){
          arr[i] += pass;
          if(i + 1 < 1001) 
          arr[ i+ 1] -= pass;
        }
     }

      for(int i = 0; i < 1001 && capacity >= 0; ++i) 
        capacity -= arr[i];  
        
      return capacity >= 0;
    }
};



