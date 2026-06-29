class Solution {
public:
    void computeLPS(string word , vector<int>& lps){
        int m = word.size();
        lps[0] = 0;
        int length = 0;
        int j = 1;
       while(j < m){
        if(word[j] == word[length]){
          length++;
          lps[j] = length;
           j++;
        }
        else{
          if(length != 0){
            length = lps[length - 1];
          }
          else{
            lps[j] = 0;
            j++;
          }
        }
       }
    }
    vector<int> search(string pat , string txt){
       int n = txt.length();
        int m = pat.length();
        vector<int> result;

        vector<int> lps(m, 0);
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pat : patterns) {
            if (!search(pat, word).empty()) {
                count++;
            }
        }
        return count;
    }
};