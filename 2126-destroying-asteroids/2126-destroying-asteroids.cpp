class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
      sort(asteroids.begin() , asteroids.end());
      int n = asteroids.size();

      long long planet = mass;
      for(int i = 0; i < n; i++){
        if(planet >= asteroids[i]){
            planet += asteroids[i];
        }
        else{
            return false;
        }
      }
      return true;
    }
};