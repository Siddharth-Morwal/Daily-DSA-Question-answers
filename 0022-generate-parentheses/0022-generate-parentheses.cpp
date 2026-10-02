class Solution {
public:
    void paranthesis( int open , int close , int n , string& s , vector<string>& res){
        if(open == n && close == n){
            res.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            paranthesis(open + 1 , close , n , s , res);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            paranthesis(open , close+1 , n , s , res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        paranthesis( 0 , 0 , n , s , res);
        return res;
    }
};
