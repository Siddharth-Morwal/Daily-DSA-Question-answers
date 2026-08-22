class Solution {
public:
    bool equal(vector<int>&a , vector<int>& b){
      for(int i = 0; i < 26; i++){
        if(a[i] != b[i]) return false;
      }
      return true;
    }
    bool checkInclusion(string s1, string s2){
      int n = s1.size();
      int m = s2.size();
      if(m < n) return false;
      vector<int> freqS1(26 , 0);
      for(char c : s1) freqS1[c-'a']++;

      vector<int> freqS2(26 , 0);

      int low = 0;
      for(int high = 0; high < m; high++){
        freqS2[s2[high] - 'a']++;

        if(high - low + 1 > n){
            freqS2[s2[low] - 'a']--;
            low++;
        }
        if(high - low + 1 == n){
          if(equal(freqS1 , freqS2)) return true;
        }
        
      }
      return false;
    }
};