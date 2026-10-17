class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> temp;
       bool inserted = false;

     for(int i = 0; i < intervals.size(); i++){
        if(!inserted && newInterval[0] < intervals[i][0]){
        temp.push_back(newInterval);
        inserted = true;
     }
       temp.push_back({intervals[i][0] , intervals[i][1]});
      }
      
      if(!inserted) temp.push_back(newInterval);

      vector<vector<int>> res;
      int start1 = temp[0][0];
      int end1 = temp[0][1];

      for(int i = 1; i < temp.size(); i++){
        int start2 = temp[i][0];
        int end2 = temp[i][1];

        if(end1 >= start2){
            end1 = max(end2 , end1);
            continue;
        }
        res.push_back({start1 , end1});
        start1 = start2;
        end1 = end2;
      }
      res.push_back({start1 , end1});
      return res;
    }
};