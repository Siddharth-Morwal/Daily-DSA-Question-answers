class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> st;
        for (int masks = 0; masks < (1 << n); masks++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (masks & (1 << i))
                    subset.push_back(nums[i]);
            }
            if (st.find(subset) == st.end()) {
                st.insert(subset);
                res.push_back(subset);
            }
        }
        return res;
    }
};