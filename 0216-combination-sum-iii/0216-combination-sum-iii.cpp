class Solution {
public:
    void fun(int n , int k , int idx , int sum , vector<int>& nums , vector<int>& diary , set<vector<int>>& res){
        if(diary.size() == k){
           if(sum == n){
             res.insert(diary);
           }
           return;
        }
           
    if (idx >= nums.size() || sum > n)
        return;
        
            diary.push_back(nums[idx]);
            sum += nums[idx];
           fun(n , k , idx + 1 , sum , nums , diary , res);
            diary.pop_back();
            sum -= nums[idx];
           fun(n , k , idx + 1 , sum , nums , diary , res);
        

    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int> nums = {1 , 2, 3 , 4 , 5 , 6 , 7 , 8 , 9};
       vector<int> diary;
       set<vector<int>> res;
       fun(n , k , 0 , 0 , nums , diary , res);
       return vector<vector<int>> (res.begin() , res.end()); 
    }
};