class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1 , 0);
      for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] ^ arr[i];
      }
        vector<int> res;
      for(auto& query : queries){
        int low = query[0];
        int high = query[1];
        
       res.push_back(prefix[high+1] ^ prefix[low]);
      }
      return res;
    }
};