class Solution {
public:
    long long gcdSum(vector<int>& nums) {
      vector<int> prefixGcd;
      int maxEl = -1;
     for(int i = 0; i < nums.size(); i++){
        maxEl = max(nums[i] , maxEl);
        prefixGcd.push_back(__gcd(nums[i] , maxEl));
     }  
     sort(prefixGcd.begin() , prefixGcd.end());
     long long result = 0;
     int i = 0;
     int j = nums.size() - 1;
     while(i < j){
        result += gcd(prefixGcd[i] , prefixGcd[j]);
        i++;
        j--;
     }
     return result;
    }
};