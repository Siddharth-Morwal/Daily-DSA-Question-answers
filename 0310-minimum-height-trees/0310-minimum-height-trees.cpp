class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       if(n==1) return {0};
       vector<vector<int>> a(n);
       vector<int> indegree(n , 0);
      for(int i = 0; i < edges.size(); i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        a[src].push_back(dest);
        a[dest].push_back(src);
        indegree[src]++;
        indegree[dest]++;
      }
      queue<int> q;
     for(int i = 0; i < n; i++){
        if(indegree[i] == 1) q.push(i);
     }
       vector<int> res;
     while(!q.empty()){
        res.clear();
        int size = q.size();
      for(int j = 0; j < size; j++){
        int node = q.front();
        q.pop();
        res.push_back(node);
         for(auto &neighbor : a[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 1) q.push(neighbor);
         }   
        } 
       }
      return res;
    }
};