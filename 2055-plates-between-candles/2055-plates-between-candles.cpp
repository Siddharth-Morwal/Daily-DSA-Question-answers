class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> candles;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                candles.push_back(i);
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + (s[i] == '*');
        }
        vector<int> res;
        for (auto& query : queries) {
            int low = query[0];
            int high = query[1];

            auto left = lower_bound(candles.begin(), candles.end(), low);
            auto right = upper_bound(candles.begin(), candles.end(), high);

            if (left == candles.end() || left == right) {
                res.push_back(0);
                continue;
            }

            right--;

            int leftcandle = *left;
            int rightcandle = *right;

            if (leftcandle >= rightcandle) {
                res.push_back(0);
            } else {
                res.push_back(prefix[rightcandle] - prefix[leftcandle]);
            }
        }

        return res;
    }
};