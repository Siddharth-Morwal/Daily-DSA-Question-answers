class Solution {
public:
    void combinations(string& digits , int i , string comb , vector<string>& res , unordered_map<char, string>& digilet){
        if(i == digits.size()){
            res.push_back(comb);
            return;
        }
        string choice = digilet[digits[i]];
        for(int j = 0; j < choice.size(); j++){
            comb.push_back(choice[j]);
            combinations(digits , i+1 , comb , res , digilet);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      int n = digits.size();
      if(digits.empty()) return res;
      unordered_map<char , string> digilet = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
      };
      combinations( digits , 0 , "" , res , digilet);
      return res;
    }
};