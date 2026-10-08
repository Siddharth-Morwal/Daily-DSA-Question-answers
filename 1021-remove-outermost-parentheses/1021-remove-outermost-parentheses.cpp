class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string res;
        for( auto c : s){
            if(c == ')'){
                count--;
            }
            if(count){
                res.push_back(c);
            }
            if(c == '('){
                count++;
            }
        }
        return res;
    }
};