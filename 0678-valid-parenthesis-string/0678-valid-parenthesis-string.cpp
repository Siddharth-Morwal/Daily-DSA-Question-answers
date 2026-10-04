class Solution {
public:
    bool solve(int i , int open , string& s , int n  , vector<vector<bool>>& t){
       t[n][0] = true;
      for(int i = n - 1; i >= 0; --i){
        for(int open = 0; open < n; ++open){
         bool isvalid = false;
        if(s[i] == '*'){
          isvalid |= t[i+1][open];
          if(open > 0) isvalid |= t[i+1][open - 1];
           if(open < n) isvalid |= t[i+1][open+1];
        }
        else if(s[i] == '('){
            isvalid |= t[i+1][open + 1];
        }
        else if(open > 0){
            isvalid |= t[i + 1][open - 1];
        }
         t[i][open] = isvalid;
      }
     }
       return t[0][0];
    }
    bool checkValidString(string s) {
      int n = s.length();
      vector<vector<bool>>t(n+1 , vector<bool>(n+1 , false));
      return solve( 0  , 0 , s , n , t);
    }

};