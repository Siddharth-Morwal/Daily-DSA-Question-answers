class Solution {
public:
    void fun(int n , int idx , int sum , vector<int>& candidates , int target , vector<int>& temp , vector<vector<int>>& result){
        if(idx == n){
            if(sum == target){
                result.push_back(temp);
            }
                return;
        }

        fun(n , idx+1 , sum , candidates , target , temp , result);
        if(candidates[idx] + sum <= target){
            temp.push_back(candidates[idx]);
            sum += candidates[idx];
           fun(n , idx , sum ,  candidates , target , temp , result);
           temp.pop_back();
           sum -= candidates[idx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       int n = candidates.size();
       int sum = 0;
       vector<int> temp;
       vector<vector<int>> result;
      fun(n , 0 , sum , candidates , target , temp , result);
      return result;
    }
};