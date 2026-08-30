class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int , vector<int>> mp;
      for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
      }
       
       vector<long long> res(n);
      for(auto& p : mp){
        const auto& group = p.second;
        long long total = accumulate(group.begin() , group.end() , 0LL);

        long long prefixTotal = 0;

        for(int i = 0; i < group.size(); i++){
            res[group[i]] = total - prefixTotal * 2 + group[i] * (2 * i - group.size());
            prefixTotal += group[i];
        } 
      }
       return res;
    }
};