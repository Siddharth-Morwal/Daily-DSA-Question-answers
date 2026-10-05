class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       vector<int> answer(n);
      for(auto& p : bookings){
        int first = p[0] , second = p[1] , seats = p[2];

        for(int i = first - 1; i < second ; ++i){
           answer[i] += seats;
           if(i + 1 < n) answer[i+1] -= seats;
        }
      }
      for(int i = 1; i < n; ++i)
        answer[i] += answer[i-1];

      return answer;
    }
};