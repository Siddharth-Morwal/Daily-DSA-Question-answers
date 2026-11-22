class Solution {
public:
    bool checkString(string s) {
      int n = s.length();
      int count = 0;
     for(int i = 0; i < n; i++){
        if(s[i] == 'b'){
         count++;
        }
        if(s[i] == 'a' && count == 0) continue;
        if(s[i] == 'a' && count > 0){
          return false;
        }
     }
     return true;
    }
};