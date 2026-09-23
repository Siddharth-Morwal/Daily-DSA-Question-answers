class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if(source == destination) return true;
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n , false);
        visited[source] = true;
        q.push(source);
       while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); ++i){
            if(!visited[adj[curr][i]]){
                if(adj[curr][i] == destination) return true;
                q.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
            }
        }
       }
       return false;
    }
};