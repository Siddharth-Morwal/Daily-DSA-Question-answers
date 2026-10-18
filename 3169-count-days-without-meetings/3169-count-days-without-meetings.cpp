class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin() , meetings.end());
       int n = meetings.size();
       int freedays = 0;

       if(days > meetings[n-1][1]){
        freedays += days - meetings[n-1][1];
       } 
       
       int start1 = meetings[0][0];
       int end1 = meetings[0][1];

       freedays = start1 - 1; 

       for(int i = 1; i < n; i++){
        int start2 = meetings[i][0];
        int end2 = meetings[i][1];

        if(end1 >= start2){
          end1 = max(end1 , end2);
        }
        else{
            freedays += start2 - end1 - 1;
            end1 = end2;
        }
       }
       freedays += days - end1;
       return freedays;
    }
};