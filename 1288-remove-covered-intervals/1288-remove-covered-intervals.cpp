class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int count = 1;
        int n = intervals.size();
        
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        
       for(int i = 1; i < n; i++){
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if(start2 > start1 && end2 > end1) count++;

        if(end2 > end1){
          start1 = start2;
          end1 = end2;
        }
       }
       return count;
    }
};