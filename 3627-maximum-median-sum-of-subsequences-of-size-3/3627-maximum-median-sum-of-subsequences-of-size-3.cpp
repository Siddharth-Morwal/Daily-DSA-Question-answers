class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        long long res = 0;
        int n = nums.size();

    //    for(int i = 0 , j = n - 1; i < j; i++ , j--){
    //        res += nums[j-1];
    //        j--;
    //    }
        for(int i = n-2; i >= n/3 ; i-=2) res+= nums[i];
        return res;
    }
};