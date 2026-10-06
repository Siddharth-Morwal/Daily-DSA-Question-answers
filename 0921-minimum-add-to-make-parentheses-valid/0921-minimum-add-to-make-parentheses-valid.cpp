class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if(st.top() == '(' && s[i] == ')' ){
                st.pop();
                continue;
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};