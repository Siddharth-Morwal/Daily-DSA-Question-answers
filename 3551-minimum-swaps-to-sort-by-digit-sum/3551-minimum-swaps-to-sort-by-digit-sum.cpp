class Solution {
public:
    int digitsum(int number) {
        int sum = 0;
        while (number > 0) {
            int rem = number % 10;
            sum += rem;
            number /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> aftersorted(nums);

        auto lambda = [&](int nums1, int nums2) {
            int num1dsum = digitsum(nums1);
            int num2dsum = digitsum(nums2);

            if (num1dsum != num2dsum)
                return num1dsum < num2dsum;

            return nums1 < nums2;
        };
        sort(begin(aftersorted), end(aftersorted), lambda);

        unordered_map<int, int> valtoidx;
        for (int i = 0; i < n; i++) {
            valtoidx[nums[i]] = i;
        }

        int swapcount = 0;
        for (int i = 0; i < n; i++) {
            int expectedval = aftersorted[i];
            int currval = nums[i];

            if (expectedval == currval)
                continue;

            int idx = valtoidx[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;

            valtoidx[expectedval] = i;
            valtoidx[currval] = idx;

            swapcount++;
        }
        return swapcount;
    }
};