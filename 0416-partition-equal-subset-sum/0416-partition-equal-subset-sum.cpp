class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int total = 0;

    for (int x : nums)
        total += x;

    if (total % 2)
        return false;

    int target = total / 2;

    bitset<10001> dp;
    dp[0] = 1;

    for (int x : nums) {
        dp |= dp << x;
    }

    return dp[target];
    }
};