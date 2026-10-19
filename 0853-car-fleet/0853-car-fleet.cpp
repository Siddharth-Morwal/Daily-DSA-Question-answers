class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      int n = position.size();
      int fleets = 0;
      vector<pair<int , double>> cars(n);
      for(int i = 0; i < n; i++){
        double time = double(target - position[i]) / speed[i];
        cars[i] = {position[i] , time};
      }

      sort(cars.rbegin() , cars.rend());

      double currentfleets = 0;

      for(int i = 0; i < n; i++){
        if(cars[i].second > currentfleets){
            fleets++;
            currentfleets = cars[i].second;
        }
      }
      return fleets; 
    }
};