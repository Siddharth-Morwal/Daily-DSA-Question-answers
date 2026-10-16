class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
      sort(arr2.begin() , arr2.end());
      int n = arr2.size();
      int ans = 0;  
    for(int i = 0; i < arr1.size(); ++i){ 
      int low = 0 , high = n - 1;
      bool valid = true;
       while(low <= high){
        int mid = low + (high - low ) / 2;
        if (arr2[mid] >= arr1[i] - d && arr2[mid] <= arr1[i] + d){
          valid = false; 
           break;
        }
        else if (arr2[mid] < arr1[i] - d){ 
            low = mid + 1;
        }
        else { 
          high = mid - 1;
        }
       }
        if(valid) ++ans;
    }
     return ans;  

    
        return ans;
    }
};