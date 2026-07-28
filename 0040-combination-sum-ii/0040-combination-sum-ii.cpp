class Solution {
public:
    void fun(int n, int idx, int target, vector<int>& candidates,
             vector<int>& diary, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(diary);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            diary.push_back(candidates[i]);

            fun(n, i + 1, target - candidates[i], candidates, diary, res);
            diary.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> diary;
        vector<vector<int>> res;
        fun(n, 0, target, candidates, diary, res);
        return res;
    }
};