class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      queue<int> q;
      vector<bool> visited(n , false);
      q.push(0);
      visited[0] = true;
     while(!q.empty()){
        int p = q.front();
        q.pop();
       for(int key : rooms[p]){
         if(!visited[key]){
            q.push(key);
            visited[key] = true;
         }
       }
     }
     for(int i = 0; i < n; ++i){
        if(!visited[i]) return false;
     }
     return true;
    }
};