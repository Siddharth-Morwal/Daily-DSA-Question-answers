class Solution {
public:
    int hammingWeight(int n) {
      int res = 1;
     while(n != 1){
        if(n & 1 ){
          ++res;
        }
        n >>= 1;
     }  
     return res;
    }
};