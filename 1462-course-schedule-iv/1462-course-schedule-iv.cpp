class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>a(numCourses);
        vector<int> indegree(numCourses , 0);
        vector<unordered_set<int>> prereq(numCourses);
       for(int i = 0; i < prerequisites.size(); ++i){
        int src = prerequisites[i][0];
        int dest = prerequisites[i][1];
        a[src].push_back(dest);
        indegree[dest]++;
        prereq[dest].insert(src);
       }
       vector<bool> res;
       queue<int> q;
      for(int i = 0; i < numCourses; ++i){
        if(indegree[i] == 0) q.push(i);
      }
      
      while(!q.empty()){
        int node = q.front();
        q.pop();
       for(int i : a[node]){
        for(int j : prereq[node]){
          prereq[i].insert(j);
        }
        indegree[i]--;
         if(indegree[i] == 0) q.push(i);
       }
      }

      int n = queries.size();
      vector<bool> ans(n , false);
      for(int i = 0; i < n; ++i){
        if(prereq[queries[i][1]].find(queries[i][0]) != prereq[queries[i][1]].end())
          ans[i] = true;;
      }
       return ans;
    }
};