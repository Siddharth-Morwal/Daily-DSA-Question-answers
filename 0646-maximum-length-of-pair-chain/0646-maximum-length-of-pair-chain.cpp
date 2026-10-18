class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      int n = pairs.size();
      int res = 1;
       sort(pairs.begin() , pairs.end() , [](vector<int>& a , vector<int>& b){
           return a[1] < b[1];
        });
      
      int start1 = pairs[0][0];
      int end1 = pairs[0][1];

      for(int i = 1; i < n; i++){
        int start2 = pairs[i][0];
        int end2 = pairs[i][1];

        if(end1 < start2){
          res++;
          start1 = start2;
          end1 = end2;
        }
      }
      return res;
    }
};