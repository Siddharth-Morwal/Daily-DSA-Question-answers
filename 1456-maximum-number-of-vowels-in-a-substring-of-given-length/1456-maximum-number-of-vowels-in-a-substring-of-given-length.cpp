class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int res = 0;
        int low = 0;
        int count = 0;
      for(int high = 0; high < n; high++){
        if(isvowel(s[high])) count++;
        int window = high - low + 1;
        if(window == k){
            res = max(res , count);
            if(isvowel(s[low])) count--;
            low++;
        }
      }
      return res;
    }
};