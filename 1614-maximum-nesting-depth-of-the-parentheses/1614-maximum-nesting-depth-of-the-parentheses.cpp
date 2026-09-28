class Solution {
public:
    int maxDepth(string s) {
      int n = s.size();
      int ans = 0;
      stack<char> st;
      for(char c : s){
        if(c == '(') st.push(c);
        else if (c == ')') st.pop();
        ans = max(ans , (int)st.size());
      }
      return ans;  
    }
};