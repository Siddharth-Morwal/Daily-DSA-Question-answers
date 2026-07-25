class Solution {
public:
    void fun(int n , int idx , int k , vector<int>& diary , vector<vector<int>>& res){
        if(diary.size() == k){
            res.push_back(diary);
            return;
        }
      for(int i = idx ; i <= n; i++){
        diary.push_back(i);
        fun( n , i+1 , k , diary , res);
        diary.pop_back();
      }
       
    }
    vector<vector<int>> combine(int n, int k) {
      vector<int> diary;
      vector<vector<int>> res;
      fun( n , 1 , k , diary , res);
      return res;
    }
};