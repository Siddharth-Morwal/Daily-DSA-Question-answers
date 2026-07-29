class Solution {
public:
 bool validspace(int i , int j , int n , int m){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
   bool dfs(int i , int j , int idx ,  vector<vector<char>>& board, string& word ){
       if(idx == word.size()) return true;
       if(!validspace(i , j , board[0].size() , board.size()) || board[i][j] != word[idx]) return false;


       char temp = board[i][j];
       board[i][j] = '#';
       
       bool found = 
        dfs(i+1 , j , idx+1 , board , word ) ||
        dfs(i , j+1 , idx+1 , board , word) ||
        dfs(i-1 , j , idx+1 , board , word ) ||
        dfs(i , j-1 , idx+1 , board , word );
        
        board[i][j] = temp;
        return found;
   }
    bool exist(vector<vector<char>>& board, string word) {
       int m = board.size();
       int n = board[0].size();
       int idx = 0;
      
        for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(dfs(i , j  , idx, board , word)) return true;
        }
        }
       return false;
    }
};