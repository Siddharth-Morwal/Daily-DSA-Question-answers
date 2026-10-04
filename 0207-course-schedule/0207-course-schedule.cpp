class Solution {
public:
    // bool cycle = false;
    // void dfs(vector<vector<int>>& a , int numCourses , int node , int parent , vector<bool>& visited , vector<bool>& path){
    //    visited[node] = 1;
    //    path[node] = 1;
    //    for(int i = 0; i < a[node].size(); i++){
    //     int neigh = a[node][i];
    //     if(visited[neigh] == 1 && path[neigh] == 1){
    //       cycle = true;
    //     }
    //     if(visited[neigh] == 0){
    //       dfs(a , numCourses , neigh , node , visited , path);
    //     }
    //    }
    //     path[node] = 0;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> a(numCourses);
       vector<int> indeg(numCourses , 0);
       for(int i = 0; i < prerequisites.size(); i++){
          int src = prerequisites[i][0];
          int dest = prerequisites[i][1];
        //   a[src].push_back(dest);
          a[dest].push_back(src);
          indeg[src]++;
       } 
       queue<int> q;
       for(int i = 0; i < numCourses; i++){
        if(indeg[i] == 0) q.push(i);
       }
       vector<int> res;
       while(!q.empty()){
         int node = q.front();
         q.pop();
         res.push_back(node);
        for(int j = 0; j < a[node].size(); j++){
          int neigh = a[node][j];
          indeg[neigh]--;
         if(indeg[neigh] == 0) q.push(neigh);
        }
       }
       if(res.size() < numCourses){
        return false;
       }
       return true;
    //    vector<bool> visited(numCourses , 0);
    //    vector<bool> path(numCourses , 0);
    //    for(int i = 0; i < numCourses ; i++){
    //     if(!visited[i]){
    //       dfs(a , numCourses , i , -1 , visited , path);
    //     }
    //    }
    //    return !cycle;
    }
};