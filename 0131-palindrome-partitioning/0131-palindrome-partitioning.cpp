class Solution {
public:
    bool isPalindrome(const string& s , int l , int r){
        int n = s.size();
      while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
      }
      return true;
    }

    void backtrack(int idx , vector<string>& curr , vector<vector<string>>& res , string& s){
        if(idx == s.size()){
           res.push_back(curr);
           return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s , idx , i)){
                curr.push_back(s.substr(idx , i - idx + 1));
                backtrack(i+1 , curr , res , s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> curr;
      backtrack(0 , curr , res , s);
      return res;
    }
};