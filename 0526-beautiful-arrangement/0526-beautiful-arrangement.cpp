class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
      vector<bool> visited(n+1 , false);
      calculate(n , visited , 1);
      return count;
    }
    void calculate(int n ,vector<bool>& visited , int idx){
      if(idx > n){
        count++;
        return;
      }
      else{
        for(int i = 1; i <= n; i++){
            if(!visited[i] && (idx % i == 0 || i % idx == 0)){
                visited[i] = true;
                calculate(n , visited ,  idx+1);
                visited[i] = false;
            }
        }
      }
    }
    
};