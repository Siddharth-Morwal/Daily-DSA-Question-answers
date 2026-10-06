class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = -1;
        int leftseen = nums[0];
        int rightseen = nums[n - 1];

        for (int i = 1, j = n - 2; i < n; ++i, --j) {
            if (nums[i] < leftseen)
                r = i;
            if (nums[j] > rightseen)
                l = j;

            leftseen = max(leftseen, nums[i]);
            rightseen = min(rightseen, nums[j]);
        }
        return r - l + 1;
    }
};