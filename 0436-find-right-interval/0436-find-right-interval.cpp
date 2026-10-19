class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[intervals[i][0]] = i;

        for (int i = 0; i < n; i++) {
            int endj = intervals[i][1];
            auto it = mp.lower_bound(endj);

            if (it != mp.end())
                res.push_back(it->second);
            else
                res.push_back(-1);
        }
        return res;
    }
};