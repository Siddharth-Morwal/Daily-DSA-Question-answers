class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAX = *max_element(nums.begin(), nums.end());

        vector<long long> freq(MAX + 1, 0);
        for (int x : nums)
            ++freq[x];
        vector<long long> gcdPairs(MAX + 1, 0);
        for (int g = MAX; g >=1; --g) {
            long long cnt = 0;
          for(int j = g; j <= MAX; j+=g)
            cnt += freq[j];
            gcdPairs[g] = cnt*(cnt - 1)/2;
           for(int j = 2 * g; j <= MAX; j+=1)
             gcdPairs[g] -= gcdPairs[j];
          
        }

        for(int i = 1; i <= MAX; i++){
            gcdPairs[i] += gcdPairs[i-1]; 
        }
  
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            answer[i] = upper_bound(gcdPairs.begin(), gcdPairs.end(), queries[i]) - gcdPairs.begin();
        }
        return answer;
    }
};